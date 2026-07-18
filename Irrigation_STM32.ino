/*
===============================================================================
        SMART IRRIGATION MONITORING USING STM32 BLUE PILL & ESP32
===============================================================================

Project       : Smart Irrigation Monitoring Using STM32 Blue Pill & ESP32
Module        : STM32 Blue Pill (Main Controller)
Platform      : STM32F103C8T6 (Blue Pill)
IDE           : Arduino IDE
Language      : C++
Author        : ShivsFoundry
Version       : 1.0
License       : MIT License

-------------------------------------------------------------------------------
Project Overview
-------------------------------------------------------------------------------

This program acts as the main controller firmware for the Smart Irrigation
Monitoring System.

The STM32 Blue Pill collects sensor data, processes irrigation conditions,
controls the water pump, and communicates with ESP32 through UART communication.

-------------------------------------------------------------------------------
Controller Functions
-------------------------------------------------------------------------------

✓ Soil Moisture Monitoring
✓ Temperature Monitoring (DHT11)
✓ Humidity Monitoring (DHT11)
✓ Rain Detection
✓ Automatic Pump Control
✓ Relay Control (Active LOW)
✓ UART Communication with ESP32
✓ Serial Debug Monitoring

-------------------------------------------------------------------------------
Hardware Configuration
-------------------------------------------------------------------------------

Component               Pin

Soil Moisture Sensor    PA0
DHT11 Sensor            PA1
Rain Sensor             PA4
Relay Module            PB0

-------------------------------------------------------------------------------
Communication
-------------------------------------------------------------------------------

STM32 Blue Pill <---- UART ----> ESP32

Baud Rate : 9600

Data Format:

moisturePercent,temperature,humidity,rainState

Example:

45,28,70,0

===============================================================================
*/


//=============================================================================
// Library Files
//=============================================================================

#include "DHT.h"


//=============================================================================
// Pin Configuration
//=============================================================================

#define SOIL_PIN PA0
#define DHT_PIN PA1
#define RAIN_PIN PA4
#define MOTOR_PIN PB0

#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);


//=============================================================================
// Variables
//=============================================================================

float temperature = 0;
float humidity = 0;

int motorState = 0;

float soilMoisturePercentage = 0;

int rainValue = 0;
int rainState = 0;       // 1 = RAINING, 0 = NO RAIN


//=============================================================================
// Soil Sensor Calibration
//=============================================================================

int dryValue = 3500;     // Soil completely dry raw value
int wetValue = 1200;     // Soil fully wet raw value


//=============================================================================
// Communication Parameters
//=============================================================================

const unsigned long sendInterval = 2000;
unsigned long lastSend = 0;


//=============================================================================
// Setup Function
//=============================================================================

void setup()
{
  Serial.begin(9600);      // USB Debug

  Serial2.begin(9600);     // UART Communication with ESP32

  pinMode(MOTOR_PIN, OUTPUT);

  digitalWrite(MOTOR_PIN, HIGH);  // Relay inactive (Active LOW)

  dht.begin();

  delay(200);

  // Initial startup packet
  Serial2.println("0,0,0,0");
  Serial.println("Sent startup packet -> 0,0,0,0");
}


//=============================================================================
// Main Loop
//=============================================================================

void loop()
{

  //-------------------------------------------------------------------------
  // Soil Moisture Reading
  //-------------------------------------------------------------------------

  int rawSoil = analogRead(SOIL_PIN);

  soilMoisturePercentage = map(rawSoil, wetValue, dryValue, 0, 100);

  soilMoisturePercentage =
      constrain(soilMoisturePercentage, 0, 100);


  //-------------------------------------------------------------------------
  // DHT11 Reading
  //-------------------------------------------------------------------------

  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h))
  {
    t = 0;
    h = 0;
  }

  temperature = t;
  humidity = h;


  //-------------------------------------------------------------------------
  // Rain Sensor Reading
  //-------------------------------------------------------------------------

  rainValue = analogRead(RAIN_PIN);

  if (rainValue < 1500)
  {
    rainState = 1;
  }
  else
  {
    rainState = 0;
  }


  //-------------------------------------------------------------------------
  // Automatic Motor Control
  //-------------------------------------------------------------------------

  if (rainState == 1)
  {
    motorState = 0;
  }
  else if (soilMoisturePercentage > 60)
  {
    motorState = 1;
  }
  else if (soilMoisturePercentage < 40)
  {
    motorState = 0;
  }


  // Active LOW Relay Control

  digitalWrite(MOTOR_PIN, motorState ? LOW : HIGH);


  //-------------------------------------------------------------------------
  // UART Transmission to ESP32
  //-------------------------------------------------------------------------

  unsigned long now = millis();

  if (now - lastSend >= sendInterval)
  {
    lastSend = now;

    String out =
        String((int)soilMoisturePercentage) + "," +
        String((int)temperature) + "," +
        String((int)humidity) + "," +
        String(rainState);


    Serial2.println(out);


    Serial.print("Sent -> ");
    Serial.println(out);


    Serial.print("RawSoil: ");
    Serial.print(rawSoil);

    Serial.print(" | Soil%: ");
    Serial.print(soilMoisturePercentage);

    Serial.print(" | Temp: ");
    Serial.print(temperature);

    Serial.print(" | Hum: ");
    Serial.print(humidity);

    Serial.print(" | RainVal: ");
    Serial.print(rainValue);

    Serial.print(" | RainState: ");
    Serial.print(rainState);

    Serial.print(" | Motor: ");
    Serial.println(motorState ? "ON" : "OFF");
  }
}