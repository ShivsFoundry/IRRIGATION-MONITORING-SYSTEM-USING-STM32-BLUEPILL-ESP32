/*
===============================================================================
        IRRIGATION MONITORING USING STM32 BLUE PILL & ESP32
===============================================================================

Project       : Smart Irrigation Monitoring Using STM32 Blue Pill & ESP32
Module        : ESP32 IoT Gateway Controller
Platform      : ESP32 Dev Module
IDE           : Arduino IDE
Language      : C++
Author        : ShivsFoundry
Version       : 1.0
License       : MIT License

-------------------------------------------------------------------------------
Project Overview
-------------------------------------------------------------------------------

This program acts as the IoT gateway controller for the Smart Irrigation
Monitoring System.

The ESP32 receives processed sensor information from the STM32 Blue Pill
through UART communication and provides internet connectivity for remote
monitoring and irrigation control.

The ESP32 performs:

• WiFi Connectivity
• ThingSpeak Cloud Data Upload
• Telegram Bot Notifications
• Remote Motor Control
• Auto / Manual Irrigation Mode
• UART Data Processing

-------------------------------------------------------------------------------
Communication Interface
-------------------------------------------------------------------------------

STM32 Blue Pill <---- UART ----> ESP32

UART Configuration:

RX Pin    : GPIO16
TX Pin    : GPIO17
Baud Rate : 9600


Received Data Format:

moisturePercent,temperature,humidity,rainState

Example:

45,28,70,0


-------------------------------------------------------------------------------
IoT Features
-------------------------------------------------------------------------------

✓ Wireless Monitoring
✓ Cloud Data Logging
✓ Telegram Alerts
✓ Remote Pump Control
✓ Automatic Irrigation Management
✓ Non-Blocking Data Handling

-------------------------------------------------------------------------------
Hardware Configuration
-------------------------------------------------------------------------------

UART RX  : GPIO16
UART TX  : GPIO17
Relay    : GPIO23

-------------------------------------------------------------------------------
Required Libraries
-------------------------------------------------------------------------------

• WiFi.h
• HTTPClient.h
• UniversalTelegramBot.h
• WiFiClientSecure.h

===============================================================================
*/


//=============================================================================
//                               Library Files
//=============================================================================

#include <WiFi.h>
#include <HTTPClient.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>


//=============================================================================
//                              WiFi Configuration
//=============================================================================

const char* ssid = "SF";
const char* password = "123456789";


//=============================================================================
//                           ThingSpeak Configuration
//=============================================================================

String apiKey = "*****************";


//=============================================================================
//                              UART Configuration
//=============================================================================

#define RX_PIN 16
#define TX_PIN 17

HardwareSerial STM(2);


//=============================================================================
//                           Telegram Configuration
//=============================================================================

#define BOT_TOKEN "8*******9:AAGZ****_Tpq4****-IIYkQ****_1C-****"
#define CHAT_ID "*********"


WiFiClientSecure secured_client;

UniversalTelegramBot bot(BOT_TOKEN, secured_client);


//=============================================================================
//                              Motor Configuration
//=============================================================================

bool autoMode = true;

int motorPin = 23;

bool motorState = false;

String lastMotorState = "0";


//=============================================================================
//                         Sensor Data Variables
//=============================================================================

String lastMoisture = "";
String lastTemp = "";
String lastHum = "";
String lastRain = "";


//=============================================================================
//                              Timer Variables
//=============================================================================

unsigned long lastThingSpeakTime = 0;
unsigned long lastTelegramPoll = 0;
unsigned long lastNotificationTime = 0;
unsigned long bootStart = 0;


// Timer intervals

const unsigned long thingSpeakInterval = 40UL * 1000UL;
const unsigned long telegramPollInterval = 1500UL;
const unsigned long notificationInterval = 60UL * 1000UL;
const unsigned long bootTimeout = 5000UL;


//=============================================================================
//                         Telegram Message Queue
//=============================================================================

bool pendingSensorNotification = false;

String pendingSensorMessage = "";

bool pendingMotorAlert = false;

String pendingMotorMessage = "";


//=============================================================================
//                              UART Buffer
//=============================================================================

String uartBuffer = "";

//=============================================================================
//                              WiFi Handler
//=============================================================================

void ensureWiFi()
{
  if (WiFi.status() == WL_CONNECTED)
    return;

  Serial.print("[WiFi] Connecting");

  WiFi.disconnect(true);

  WiFi.begin(ssid, password);


  unsigned long start = millis();


  while (WiFi.status() != WL_CONNECTED &&
         millis() - start < 4000)
  {
    Serial.print(".");
    delay(50);
  }


  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println(" OK");
  }
  else
  {
    Serial.println(" FAILED");
  }
}



//=============================================================================
//                      Telegram Sensor Notification Queue
//=============================================================================

void queueSensorNotification(
    const String &moisture,
    const String &motor,
    const String &temp,
    const String &hum,
    const String &rain)
{

  pendingSensorMessage =
      String("🌱 Smart Irrigation Data Update\n\n");


  pendingSensorMessage +=
      String("• Soil Moisture: ") + moisture + "\n";


  pendingSensorMessage +=
      String("• Temperature: ") + temp + "°C\n";


  pendingSensorMessage +=
      String("• Humidity: ") + hum + "%\n";


  pendingSensorMessage +=
      String("• Rain: ") +
      (rain == "1" ? "Detected" : "No Rain") +
      "\n";


  pendingSensorMessage +=
      String("• Motor: ") +
      (motor == "1" ? "ON" : "OFF") +
      "\n";


  pendingSensorMessage +=
      String("• Mode: ") +
      (autoMode ? "AUTO" : "MANUAL");


  pendingSensorNotification = true;

}



//=============================================================================
//                        Telegram Motor Alert Queue
//=============================================================================

void queueMotorAlert(const String &motorStateStr)
{

  pendingMotorMessage =
      String("⚙️ Motor Status Changed\n");


  pendingMotorMessage +=
      String("Motor is now: ") +
      (motorStateStr == "1" ? "ON" : "OFF") +
      "\n";


  pendingMotorMessage +=
      String("Mode: ") +
      (autoMode ? "AUTO" : "MANUAL");


  pendingMotorAlert = true;

}



//=============================================================================
//                         Send Telegram Queue
//=============================================================================

void flushTelegramQueue()
{

  if (WiFi.status() != WL_CONNECTED)
  {

    Serial.println(
      "[Telegram] WiFi not connected, skipping queued sends"
    );

    return;

  }



  if (pendingMotorAlert)
  {

    Serial.println(
      "[Telegram] Sending motor alert"
    );


    bot.sendMessage(
      CHAT_ID,
      pendingMotorMessage,
      "Markdown"
    );


    pendingMotorAlert = false;

  }



  if (pendingSensorNotification)
  {

    Serial.println(
      "[Telegram] Sending sensor notification"
    );


    bot.sendMessage(
      CHAT_ID,
      pendingSensorMessage,
      "Markdown"
    );


    pendingSensorNotification = false;

  }

}



//=============================================================================
//                         ThingSpeak Upload
//=============================================================================

void uploadToThingSpeak(
    const String &moisture,
    const String &motor,
    const String &temp,
    const String &hum,
    const String &rain)
{


  if (WiFi.status() != WL_CONNECTED)
  {

    Serial.println(
      "[ThingSpeak] WiFi not connected. Skipping upload."
    );

    return;

  }



  HTTPClient http;



  String url =
      String("http://api.thingspeak.com/update?api_key=")
      + apiKey
      + "&field1=" + moisture
      + "&field2=" + motor
      + "&field3=" + temp
      + "&field4=" + hum
      + "&field5=" + rain;



  Serial.println(
      "[ThingSpeak] Uploading..."
  );



  http.begin(url);


  int code = http.GET();



  Serial.println(
      String("[ThingSpeak] HTTP code: ")
      + String(code)
  );


  http.end();

}



//=============================================================================
//                         Telegram Command Handler
//=============================================================================

void pollTelegram()
{

  int newMsgs =
      bot.getUpdates(
        bot.last_message_received + 1
      );



  if (newMsgs > 0)
  {

    Serial.println(
      String("[Telegram] ")
      + String(newMsgs)
      + " new messages"
    );



    for (int i = 0; i < newMsgs; ++i)
    {


      String text =
          bot.messages[i].text;



      String chatID =
          String(bot.messages[i].chat_id);



      Serial.println(
          "[Telegram] Msg: "
          + text
      );



      if (text == "/auto")
      {

        autoMode = true;


        bot.sendMessage(
          chatID,
          "🔄 Motor Mode Set to AUTO",
          "Markdown"
        );

      }


      else if (text == "/manual_on")
      {

        autoMode = false;


        motorState = true;


        digitalWrite(
          motorPin,
          LOW
        );


        lastMotorState = "1";


        bot.sendMessage(
          chatID,
          "⚡ Motor TURNED ON (Manual Mode)",
          ""
        );

      }


      else if (text == "/manual_off")
      {

        autoMode = false;


        motorState = false;


        digitalWrite(
          motorPin,
          HIGH
        );


        lastMotorState = "0";


        bot.sendMessage(
          chatID,
          "⛔ Motor TURNED OFF (Manual Mode)",
          ""
        );

      }


      else if (text == "/status")
      {

        String status =
            motorState ? "ON" : "OFF";


        bot.sendMessage(
          chatID,
          "📊 Motor is currently: "
          + status,
          ""
        );

      }


      else
      {

        bot.sendMessage(
          chatID,
          "❌ Invalid command.\nUse /auto, /manual_on, /manual_off, or /status",
          ""
        );

      }

    }

  }

}

//=============================================================================
//                         UART Sensor Data Parser
//=============================================================================

void handleSensorLine(String line)
{

  line.trim();


  if (line.length() == 0)
    return;



  Serial.println(
      "[UART] Received: " + line
  );



  const int MAX_FIELDS = 6;


  String parts[MAX_FIELDS];


  int idx = 0;


  int start = 0;



  for (int i = 0;
       i <= line.length() && idx < MAX_FIELDS;
       ++i)
  {

    if (i == line.length() || line[i] == ',')
    {

      parts[idx++] =
          line.substring(start, i);


      start = i + 1;

    }

  }



  if (idx < 4)
  {

    Serial.println(
      "[UART] Invalid packet (fewer than 4 fields). Ignoring."
    );


    return;

  }



  String moisture = parts[0];

  String temp = parts[1];

  String hum = parts[2];

  String rain = parts[3];



  if (moisture.length() == 0)

    moisture =
      (lastMoisture.length() ? lastMoisture : "0");



  if (temp.length() == 0)

    temp =
      (lastTemp.length() ? lastTemp : "0");



  if (hum.length() == 0)

    hum =
      (lastHum.length() ? lastHum : "0");



  if (rain.length() == 0)

    rain =
      (lastRain.length() ? lastRain : "0");




  //-------------------------------------------------------------------------
  // Automatic Motor Control
  //-------------------------------------------------------------------------

  bool desiredMotor = motorState;



  if (autoMode)
  {

    int moistVal =
        moisture.toInt();



    if (rain == "1")
    {

      desiredMotor = false;

    }

    else
    {

      if (moistVal >= 100)

        desiredMotor = true;


      else if (moistVal <= 0)

        desiredMotor = false;


      else if (moistVal > 60)

        desiredMotor = true;


      else if (moistVal < 40)

        desiredMotor = false;

    }



    motorState = desiredMotor;



    digitalWrite(
      motorPin,
      motorState ? LOW : HIGH
    );

  }




  String motorStr =
      motorState ? "1" : "0";



  if (motorStr != lastMotorState)
  {

    lastMotorState = motorStr;


    queueMotorAlert(motorStr);

  }




  if (moisture != lastMoisture ||
      temp != lastTemp ||
      hum != lastHum ||
      rain != lastRain)
  {


    lastMoisture = moisture;

    lastTemp = temp;

    lastHum = hum;

    lastRain = rain;



    queueSensorNotification(
      lastMoisture,
      lastMotorState,
      lastTemp,
      lastHum,
      lastRain
    );

  }

}



//=============================================================================
//                              Setup Function
//=============================================================================

void setup()
{

  Serial.begin(115200);


  delay(10);



  // UART Communication with STM32

  STM.begin(
    9600,
    SERIAL_8N1,
    RX_PIN,
    TX_PIN
  );



  pinMode(
    motorPin,
    OUTPUT
  );



  // Relay OFF (Active LOW)

  digitalWrite(
    motorPin,
    HIGH
  );



  // Disable SSL certificate checking

  secured_client.setInsecure();



  ensureWiFi();



  if (WiFi.status() == WL_CONNECTED)
  {

    bot.sendMessage(
      CHAT_ID,
      "🚀 ESP32 Started\nSmart Irrigation System Online!",
      ""
    );

  }

  else
  {

    Serial.println(
      "[Setup] WiFi not connected: Telegram startup message skipped"
    );

  }



  bootStart = millis();


  lastThingSpeakTime = millis();


  lastTelegramPoll = millis();


  lastNotificationTime = millis();



  Serial.println(
    "[Setup] Ready."
  );

}



//=============================================================================
//                               Main Loop
//=============================================================================

void loop()
{

  //-------------------------------------------------------------------------
  // Maintain WiFi Connection
  //-------------------------------------------------------------------------

  if (WiFi.status() != WL_CONNECTED)
  {

    ensureWiFi();

  }



  //-------------------------------------------------------------------------
  // UART Data Reception
  //-------------------------------------------------------------------------

  while (STM.available())
  {


    char c =
        (char)STM.read();



    if (c == '\r')
      continue;



    if (c == '\n')
    {

      if (uartBuffer.length() > 0)
      {

        handleSensorLine(
          uartBuffer
        );


        uartBuffer = "";

      }

    }

    else
    {

      uartBuffer += c;



      if (uartBuffer.length() > 200)
      {

        uartBuffer =
          uartBuffer.substring(
            uartBuffer.length() - 200
          );

      }

    }

  }




  unsigned long now =
      millis();




  //-------------------------------------------------------------------------
  // Boot Safety Handling
  //-------------------------------------------------------------------------

  if (lastMoisture.length() == 0 &&
      (now - bootStart > bootTimeout))
  {


    Serial.println(
      "[Boot] No STM32 data received at boot. Sending safe defaults and Telegram notice."
    );



    lastMoisture = "0";

    lastTemp = "0";

    lastHum = "0";

    lastRain = "0";

    lastMotorState = "0";



    uploadToThingSpeak(
      lastMoisture,
      lastMotorState,
      lastTemp,
      lastHum,
      lastRain
    );



    pendingSensorMessage =
      String("⚠️ No sensor data received after boot. Sending safe values.");



    pendingSensorNotification = true;



    bootStart =
      now + 86400000UL;

  }




  //-------------------------------------------------------------------------
  // ThingSpeak Periodic Upload
  //-------------------------------------------------------------------------

  if (now - lastThingSpeakTime >= thingSpeakInterval)
  {

    lastThingSpeakTime = now;



    if (lastMoisture.length() &&
        lastTemp.length() &&
        lastHum.length() &&
        lastRain.length())
    {

      uploadToThingSpeak(
        lastMoisture,
        lastMotorState,
        lastTemp,
        lastHum,
        lastRain
      );

    }

    else
    {

      Serial.println(
        "[ThingSpeak] Skipping - no sensor data yet"
      );

    }

  }




  //-------------------------------------------------------------------------
  // Telegram Polling
  //-------------------------------------------------------------------------

  if (now - lastTelegramPoll >= telegramPollInterval)
  {

    lastTelegramPoll = now;


    pollTelegram();


    flushTelegramQueue();

  }




  //-------------------------------------------------------------------------
  // Periodic Sensor Notification
  //-------------------------------------------------------------------------

  if (now - lastNotificationTime >= notificationInterval)
  {

    lastNotificationTime = now;



    if (lastMoisture.length())
    {

      queueSensorNotification(
        lastMoisture,
        lastMotorState,
        lastTemp,
        lastHum,
        lastRain
      );

    }

  }



  // Background task handling

  yield();

}