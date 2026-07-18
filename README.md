# IRRIGATION-MONITORING-SYSTEM-USING-STM32-BLUEPILL-ESP32
A dual-microcontroller IoT-based smart irrigation monitoring system using STM32 Blue Pill and ESP32 with automatic irrigation control, ThingSpeak cloud integration, Telegram bot notifications, and real-time sensor monitoring.
# 🌱 IRRIGATION MONITORING SYSTEM USING STM32 BLUEPILL & ESP32

<div align="center">

### Intelligent IoT-Based Irrigation Monitoring and Automation System

*A dual-microcontroller embedded system that combines the real-time processing capability of the STM32 Blue Pill with the wireless connectivity of the ESP32 to provide automatic irrigation control, cloud-based monitoring, and remote management.*

![Platform](https://img.shields.io/badge/Platform-STM32%20BluePill%20%7C%20ESP32-blue)
![Language](https://img.shields.io/badge/Language-C%2B%2B-orange)
![IDE](https://img.shields.io/badge/IDE-Arduino%20IDE-success)
![Communication](https://img.shields.io/badge/Communication-UART-green)
![Cloud](https://img.shields.io/badge/Cloud-ThingSpeak-yellow)
![Remote](https://img.shields.io/badge/Remote-Telegram%20Bot-2CA5E0)
![License](https://img.shields.io/badge/License-MIT-red)

</div>

---

# 📖 Overview

**Irrigation Monitoring System Using STM32 BluePill & ESP32** is an IoT-enabled smart irrigation system developed to automate irrigation by continuously monitoring environmental conditions and controlling a water pump based on real-time sensor data.

The project adopts a **dual-microcontroller architecture** to separate embedded control from internet communication. The **STM32 Blue Pill** performs all time-critical operations such as sensor acquisition, irrigation decision-making, and relay control, while the **ESP32** acts as an IoT gateway responsible for Wi-Fi connectivity, ThingSpeak cloud integration, Telegram Bot communication, and remote monitoring.

By distributing these responsibilities across two dedicated controllers, the system achieves improved reliability, stable real-time performance, and uninterrupted cloud communication without affecting irrigation control.

The system continuously monitors soil moisture, ambient temperature, humidity, and rainfall conditions to determine whether irrigation is required. Sensor data is transmitted from the STM32 to the ESP32 using UART communication, enabling wireless monitoring and remote interaction through cloud services and Telegram.

---

# ✨ Key Features

- 🌱 Real-Time Soil Moisture Monitoring
- 🌡 Temperature Monitoring using DHT11
- 💧 Humidity Monitoring
- 🌧 Rain Detection
- 🚰 Automatic Irrigation Control
- ⚙ Active-Low Relay Operation
- 📡 UART Communication between STM32 & ESP32
- ☁ ThingSpeak Cloud Integration
- 🤖 Telegram Bot Notifications
- 📲 Remote Motor Control
- 🔄 Automatic and Manual Irrigation Modes
- 📊 Live Environmental Data Logging
- 📈 Historical Data Visualization
- 📶 Wi-Fi Connectivity using ESP32
- 🛠 Non-Blocking ESP32 Firmware Architecture
- ⚡ Low-Cost Embedded Hardware Design

---

# 🎯 Project Objectives

The primary objective of this project is to develop an intelligent irrigation monitoring system capable of reducing manual intervention while improving water management through automation and IoT technologies.

The project focuses on:

- Monitoring critical environmental parameters in real time.
- Automating irrigation based on soil moisture and rainfall.
- Preventing unnecessary irrigation during rain.
- Providing remote access through the Internet.
- Recording environmental data for analysis.
- Enabling users to control the irrigation system remotely.
- Building a modular embedded system that can be expanded with additional sensors and cloud services.

---

# 🧠 Why Two Microcontrollers?

Unlike conventional IoT projects that rely on a single Wi-Fi-enabled controller, this system separates embedded processing and internet communication into two dedicated devices.

## STM32 Blue Pill — Main Controller

The STM32 Blue Pill is responsible for all real-time embedded operations.

Its responsibilities include:

- Reading soil moisture values
- Reading temperature
- Reading humidity
- Detecting rainfall
- Processing sensor data
- Executing irrigation logic
- Controlling the relay module
- Transmitting processed data to the ESP32 through UART

The STM32 operates independently of the internet, ensuring stable and deterministic performance.

---

## ESP32 — IoT Communication Controller

The ESP32 serves as the wireless communication gateway.

Its responsibilities include:

- Connecting to Wi-Fi
- Receiving sensor data from STM32
- Uploading data to ThingSpeak
- Sending Telegram notifications
- Receiving Telegram commands
- Supporting automatic and manual irrigation modes
- Managing cloud communication

Separating internet communication from embedded control prevents network delays from affecting irrigation decisions.

> [!IMPORTANT]
> The STM32 Blue Pill continues monitoring sensors and controlling irrigation even if the ESP32 temporarily loses its internet connection. Cloud services are restored automatically once Wi-Fi connectivity returns.

---

# 🚀 System Capabilities

The completed system provides the following capabilities:

| Feature | Description |
|:---------|:------------|
| Soil Moisture Monitoring | Continuously measures soil moisture levels. |
| Temperature Monitoring | Measures ambient temperature using the DHT11 sensor. |
| Humidity Monitoring | Measures relative humidity. |
| Rain Detection | Detects rainfall and immediately disables irrigation. |
| Automatic Pump Control | Operates the pump based on environmental conditions. |
| UART Communication | Transfers sensor data from STM32 to ESP32. |
| Wi-Fi Connectivity | Enables internet access through the ESP32. |
| Cloud Monitoring | Uploads real-time data to ThingSpeak. |
| Telegram Integration | Provides notifications and remote commands. |
| Manual Pump Control | Allows users to operate the pump remotely. |
| Historical Data Logging | Stores sensor readings on the cloud for analysis. |

---

# 💡 Applications

This project can be deployed in various agricultural and environmental monitoring scenarios, including:

- Smart Agriculture
- Precision Farming
- Home Gardens
- Greenhouses
- Plant Nurseries
- Drip Irrigation Systems
- Educational IoT Projects
- Embedded Systems Research
- Environmental Monitoring
- Agricultural Automation

---

# 🏆 Project Highlights

- Dual Microcontroller Architecture
- Reliable Real-Time Embedded Control
- Internet-Enabled Remote Monitoring
- Automatic Water Conservation
- Modular Firmware Design
- Cloud-Based Data Logging
- Remote Irrigation Management
- Low Hardware Cost
- Easy to Expand and Customize
- Suitable for Academic and Industrial Learning

---

> [!NOTE]
> This project is designed to demonstrate how embedded real-time control can be combined with IoT connectivity using two dedicated microcontrollers. By separating hardware control from wireless communication, the system achieves greater reliability, improved scalability, and easier maintenance compared to single-controller implementations.
> # 🛠 Hardware Requirements

The following hardware components are required to build and operate the **Irrigation Monitoring Using STM32 BluePill & ESP32** system. All components have been selected to achieve a reliable, low-cost, and easily reproducible IoT irrigation monitoring solution.

| Component | Quantity | Description |
|:----------|:-------:|:------------|
| STM32 Blue Pill (STM32F103C8T6) | 1 | Main embedded controller responsible for sensor acquisition and irrigation control |
| ESP32 Development Board | 1 | IoT controller providing Wi-Fi connectivity and cloud communication |
| Soil Moisture Sensor | 1 | Measures the moisture content of the soil |
| DHT11 Sensor | 1 | Measures ambient temperature and relative humidity |
| Rain Sensor Module | 1 | Detects rainfall conditions |
| Relay Module (Active-Low) | 1 | Controls the water pump |
| DC Water Pump | 1 | Irrigation actuator |
| External Power Supply | 1 | Supplies power to the complete system |
| Breadboard / PCB | 1 | Circuit assembly |
| Jumper Wires | As Required | Electrical connections |

---

# 💻 Software Requirements

The project firmware is developed using the Arduino ecosystem for both controllers.

| Software | Purpose |
|:----------|:--------|
| Arduino IDE | Firmware development and uploading |
| STM32 Arduino Core | Programming STM32 Blue Pill |
| ESP32 Arduino Core | Programming ESP32 |
| ThingSpeak | Cloud data monitoring |
| Telegram | Remote monitoring and motor control |

---

# 📚 Required Libraries

## STM32 Blue Pill

Install the following library before compiling the STM32 firmware.

| Library | Purpose |
|:---------|:--------|
| DHT | Temperature and humidity sensor support |

---

## ESP32

Install the following libraries before compiling the ESP32 firmware.

| Library | Purpose |
|:---------|:--------|
| WiFi | Wi-Fi connectivity |
| HTTPClient | HTTP communication |
| WiFiClientSecure | Secure network communication |
| UniversalTelegramBot | Telegram Bot integration |

> [!TIP]
> All required libraries can be installed directly from the **Arduino IDE Library Manager**.

---

# 🔌 Hardware Architecture

The project uses two independent microcontrollers connected through UART communication.

```text
                     Soil Moisture Sensor
                              │
                              │
                     DHT11 Temperature Sensor
                              │
                              │
                         Rain Sensor
                              │
                              ▼
                 ┌─────────────────────────┐
                 │     STM32 Blue Pill     │
                 │                         │
                 │ Sensor Processing       │
                 │ Irrigation Logic        │
                 │ Relay Control           │
                 └──────────┬──────────────┘
                            │
                     UART Communication
                            │
                            ▼
                 ┌─────────────────────────┐
                 │         ESP32           │
                 │                         │
                 │ Wi-Fi Connectivity      │
                 │ ThingSpeak Upload       │
                 │ Telegram Bot            │
                 │ Remote Commands         │
                 └──────────┬──────────────┘
                            │
                       Internet
                            │
               ┌────────────┴─────────────┐
               ▼                          ▼
        ThingSpeak Cloud          Telegram Bot
```

---

# 🔗 Communication Architecture

The system is divided into two functional layers.

## STM32 Blue Pill Layer

Responsible for:

- Reading all connected sensors
- Processing environmental conditions
- Automatic irrigation control
- Relay operation
- Preparing UART data packets
- Transmitting sensor data to ESP32

---

## ESP32 Layer

Responsible for:

- Receiving UART data
- Connecting to Wi-Fi
- Uploading data to ThingSpeak
- Sending Telegram notifications
- Receiving Telegram commands
- Manual irrigation control
- Cloud communication

---

# 📡 UART Communication

The STM32 Blue Pill and ESP32 communicate using **UART Serial Communication**.

| Parameter | Value |
|:----------|:------|
| Communication Protocol | UART |
| Baud Rate | **9600 bps** |
| Data Bits | 8 |
| Stop Bits | 1 |
| Parity | None |

The STM32 periodically transmits sensor information in CSV format.

Example:

```text
65,31,72,0
```

Where:

| Field | Description |
|:------|:------------|
| 65 | Soil Moisture (%) |
| 31 | Temperature (°C) |
| 72 | Humidity (%) |
| 0 | Rain Status (0 = No Rain, 1 = Rain Detected) |

---

# 📌 STM32 Blue Pill Pin Configuration

| Peripheral | STM32 Pin | Description |
|:-----------|:---------:|:------------|
| Soil Moisture Sensor | PA0 | Analog Input |
| DHT11 Data | PA1 | Digital Input |
| Rain Sensor | PA4 | Analog Input |
| Relay Module | PB0 | Digital Output (Active-Low) |
| UART TX | PA2 | Data Transmission to ESP32 |
| UART RX | PA3 | Reserved for UART Communication |

---

# 📌 ESP32 Pin Configuration

| Peripheral | ESP32 Pin | Description |
|:-----------|:---------:|:------------|
| UART RX | GPIO16 | Receives data from STM32 |
| UART TX | GPIO17 | Reserved for UART Communication |
| Relay Output | GPIO23 | Active-Low Relay Control |

---

# 🔧 Wiring Connections

## STM32 Blue Pill Connections

| Component | STM32 Pin |
|:----------|:---------:|
| Soil Moisture Sensor | PA0 |
| DHT11 Sensor | PA1 |
| Rain Sensor | PA4 |
| Relay IN | PB0 |
| UART TX | PA2 |
| UART RX | PA3 |
| 3.3V | Sensor VCC |
| GND | Common Ground |

---

## ESP32 Connections

| Component | ESP32 Pin |
|:----------|:---------:|
| STM32 TX | GPIO16 (RX2) |
| STM32 RX | GPIO17 (TX2) |
| Relay IN | GPIO23 |
| GND | Common Ground |

> [!IMPORTANT]
> A **common ground (GND)** connection between the STM32 Blue Pill, ESP32, sensors, relay module, and power supply is mandatory for reliable UART communication and stable system operation.

---

# ⚡ Power Requirements

| Device | Operating Voltage |
|:--------|:-----------------:|
| STM32 Blue Pill | 3.3V |
| ESP32 | 3.3V |
| DHT11 | 3.3V–5V |
| Soil Moisture Sensor | 3.3V–5V |
| Rain Sensor | 3.3V–5V |
| Relay Module | 5V (Typical) |
| Water Pump | External Supply (According to Pump Rating) |

> [!WARNING]
> Do **not** power the water pump directly from the STM32 Blue Pill or ESP32. Always use a suitable external power supply through the relay module to prevent damage to the microcontrollers.

---

# 📦 Project Folder Structure

Organize the firmware in your repository as shown below.

```text
Firmware/
│
├── STM32_BluePill/
│   └── Smart_Irrigation_STM32.ino
│
└── ESP32/
    └── Smart_Irrigation_ESP32.ino
```

This structure keeps the firmware organized and allows each controller to be developed and maintained independently.
# 🚀 Firmware Installation

This section provides a complete guide for preparing the development environment, installing the required libraries, configuring the Arduino IDE, and uploading the firmware to both the **STM32 Blue Pill** and **ESP32**.

Following these steps ensures both microcontrollers communicate correctly and the complete irrigation monitoring system operates as intended.

---

# 💻 Development Environment

The entire project has been developed using the **Arduino IDE**, allowing both the STM32 Blue Pill and ESP32 to be programmed within a single development environment.

| Software | Version |
|:----------|:-------:|
| Arduino IDE | 2.x (Recommended) |
| Programming Language | C++ |
| Framework | Arduino Framework |

---

# 📥 Installing Arduino IDE

If Arduino IDE is not already installed on your computer:

1. Visit the official Arduino website.
2. Download the latest Arduino IDE.
3. Install the software.
4. Restart your computer if necessary.

Official Website:

> https://www.arduino.cc/en/software

---

# ⚙ Installing STM32 Board Package

Before uploading firmware to the STM32 Blue Pill, install the STM32 board package.

### Step 1

Open:

```text
Arduino IDE
    ↓
File
    ↓
Preferences
```

---

### Step 2

Locate:

```text
Additional Boards Manager URLs
```

Add:

```text
https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json
```

Click **OK**.

---

### Step 3

Open:

```text
Tools
    ↓
Board
    ↓
Boards Manager
```

Search for:

```text
STM32
```

Install:

```text
STM32 MCU based boards
by STMicroelectronics
```

---

# ⚙ Installing ESP32 Board Package

Open:

```text
Tools
    ↓
Board
    ↓
Boards Manager
```

Search:

```text
ESP32
```

Install:

```text
ESP32
by Espressif Systems
```

---

# 📚 Installing Required Libraries

Install the following libraries from the **Arduino Library Manager**.

Open:

```text
Sketch
    ↓
Include Library
    ↓
Manage Libraries
```

---

## STM32 Firmware Libraries

| Library | Required |
|:---------|:--------:|
| DHT Sensor Library | ✅ |
| Adafruit Unified Sensor | ✅ |

---

## ESP32 Firmware Libraries

| Library | Required |
|:---------|:--------:|
| WiFi | ✅ |
| HTTPClient | ✅ |
| WiFiClientSecure | ✅ |
| UniversalTelegramBot | ✅ |

---

# 📁 Opening the Firmware

The repository contains two separate firmware files.

```text
Firmware/
│
├── STM32_BluePill/
│      Smart_Irrigation_STM32.ino
│
└── ESP32/
       Smart_Irrigation_ESP32.ino
```

Each firmware should be uploaded independently.

---

# 🔧 Uploading Firmware to STM32 Blue Pill

## Step 1

Connect the STM32 Blue Pill to your computer using an appropriate USB-to-Serial programmer or STM32 programmer.

---

## Step 2

Open:

```text
Smart_Irrigation_STM32.ino
```

---

## Step 3

Select the board.

```text
Tools
    ↓
Board
    ↓
STM32 MCU Based Boards
    ↓
Generic STM32F1 Series
```

---

## Step 4

Configure the board settings.

| Setting | Value |
|:---------|:------|
| Board Part Number | BluePill F103C8 |
| Upload Method | STM32CubeProgrammer / Serial *(according to your setup)* |
| CPU Speed | 72 MHz |
| USB Support | Disabled |
| Optimize | Smallest (-Os) |

---

## Step 5

Select the correct COM Port.

```text
Tools
    ↓
Port
```

---

## Step 6

Click:

```text
Verify
```

Resolve any compilation errors before continuing.

---

## Step 7

Click:

```text
Upload
```

Wait until the upload completes successfully.

---

## Step 8

Open the Serial Monitor.

Set the baud rate to:

```text
9600
```

The STM32 should begin transmitting sensor data.

---

# 🌐 Uploading Firmware to ESP32

## Step 1

Connect the ESP32 development board using a USB cable.

---

## Step 2

Open:

```text
Smart_Irrigation_ESP32.ino
```

---

## Step 3

Select the board.

```text
Tools
    ↓
Board
    ↓
ESP32 Arduino
    ↓
ESP32 Dev Module
```

---

## Step 4

Configure the board settings.

| Setting | Value |
|:---------|:------|
| Board | ESP32 Dev Module |
| Flash Frequency | 80 MHz |
| Flash Mode | QIO |
| Partition Scheme | Default |
| Upload Speed | 115200 |
| PSRAM | Disabled *(if unavailable)* |

---

## Step 5

Select the correct COM Port.

```text
Tools
    ↓
Port
```

---

## Step 6

Before uploading, update the following credentials inside the ESP32 firmware.

### Wi-Fi Credentials

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

---

### ThingSpeak Write API Key

```cpp
String apiKey = "YOUR_THINGSPEAK_WRITE_API_KEY";
```

---

### Telegram Bot Token

```cpp
#define BOT_TOKEN "YOUR_BOT_TOKEN"
```

---

### Telegram Chat ID

```cpp
#define CHAT_ID "YOUR_CHAT_ID"
```

---

## Step 7

Click:

```text
Verify
```

Ensure the firmware compiles without errors.

---

## Step 8

Click:

```text
Upload
```

Wait for the upload to complete.

---

## Step 9

Open the Serial Monitor.

Set the baud rate to:

```text
115200
```

The ESP32 should initialize, connect to Wi-Fi, establish communication with the STM32, and begin transmitting data to the configured cloud services.

---

# ✅ Verifying Successful Operation

After both firmware files have been uploaded successfully, verify the following:

| Check | Expected Result |
|:------|:----------------|
| STM32 Firmware Upload | Successful |
| ESP32 Firmware Upload | Successful |
| UART Communication | Sensor data received by ESP32 |
| Wi-Fi Connection | Connected |
| ThingSpeak | Data updates successfully |
| Telegram Bot | Online and responsive |
| Relay Module | Operates correctly |
| Automatic Irrigation | Functional |
| Manual Telegram Control | Functional |

---

# 🔍 First Power-Up Checklist

Before deploying the system, confirm the following:

- STM32 Blue Pill powers up correctly.
- ESP32 connects to the configured Wi-Fi network.
- UART communication is functioning.
- Sensor values appear in the Serial Monitor.
- ThingSpeak receives live sensor data.
- Telegram Bot responds to commands.
- Relay switches correctly according to sensor conditions.
- Water pump operates as expected.

> [!IMPORTANT]
> **Upload the STM32 firmware first, followed by the ESP32 firmware.** This ensures that the ESP32 immediately receives valid UART data when it starts, allowing cloud synchronization and remote monitoring to begin without delays.

# ☁️ ThingSpeak Cloud Integration

The **ESP32** acts as the IoT gateway of the system by receiving processed sensor data from the STM32 Blue Pill through UART communication and uploading it to the **ThingSpeak Cloud Platform**.

ThingSpeak enables users to visualize environmental data in real time, analyze historical trends, and remotely monitor irrigation conditions from any internet-connected device.

---

# 🌐 What is ThingSpeak?

ThingSpeak is an IoT cloud platform developed by **MathWorks** for collecting, storing, visualizing, and analyzing sensor data.

Within this project, ThingSpeak is used to:

- Store real-time sensor readings
- Display live environmental conditions
- Generate historical graphs
- Monitor irrigation status remotely
- Analyze irrigation performance over time

---

# ✨ Features Used

- Real-Time Data Logging
- Cloud Storage
- Live Graph Visualization
- Historical Data Analysis
- Internet-Based Monitoring
- Multi-Field Sensor Recording

---

# 🛠 Creating a ThingSpeak Account

If you do not already have a ThingSpeak account:

1. Visit the ThingSpeak website.
2. Create a free MathWorks account.
3. Verify your email address.
4. Sign in to the ThingSpeak dashboard.

Official Website:

```text
https://thingspeak.com/
```

---

# 📡 Creating a New Channel

After signing in:

```text
Channels
      ↓
New Channel
```

Enter an appropriate channel name.

Example:

```text
Smart Irrigation Monitoring
```

---

# 📊 Configure Channel Fields

Enable the following five fields exactly as shown.

| Field | Parameter |
|:------|:----------|
| Field 1 | Soil Moisture (%) |
| Field 2 | Motor Status |
| Field 3 | Temperature (°C) |
| Field 4 | Humidity (%) |
| Field 5 | Rain Status |

After configuring the fields:

Click

```text
Save Channel
```

---

# 🔑 Obtaining the Write API Key

After creating the channel:

```text
Channel Settings
      ↓
API Keys
```

Locate:

```text
Write API Key
```

Copy the generated key.

Example:

```cpp
String apiKey = "YOUR_WRITE_API_KEY";
```

Replace the placeholder inside the ESP32 firmware with your own Write API Key.

---

# ☁️ Upload Process

During operation, the ESP32 periodically uploads sensor data to ThingSpeak using an HTTP GET request.

The uploaded information includes:

- Soil Moisture
- Motor Status
- Temperature
- Humidity
- Rain Detection Status

Each successful upload automatically updates the cloud dashboard.

---

# 📈 Cloud Data Flow

```text
STM32 Blue Pill
        │
Sensor Processing
        │
        ▼
UART Communication
        │
        ▼
ESP32
        │
Wi-Fi Connection
        │
        ▼
ThingSpeak Cloud
        │
        ▼
Real-Time Dashboard
```

---

# 📊 Example Dashboard

After successful configuration, the dashboard displays:

- Soil Moisture Graph
- Temperature Graph
- Humidity Graph
- Rain Detection Status
- Motor Status

The graphs are automatically updated whenever new sensor data is uploaded.

---

# 🤖 Telegram Bot Integration

To enable remote monitoring and irrigation control, the ESP32 communicates with a **Telegram Bot** using the Telegram Bot API.

The bot allows users to:

- Receive automatic notifications
- Monitor irrigation status
- Check motor state
- Switch between Automatic and Manual modes
- Remotely control the irrigation pump

---

# ✨ Telegram Features

- Remote Monitoring
- Automatic Notifications
- Manual Pump Control
- Automatic Mode Selection
- Motor Status Updates
- Internet-Based Control
- Secure Bot Communication

---

# 📱 Creating a Telegram Bot

Open the Telegram application.

Search for:

```text
BotFather
```

Start a conversation and execute the following command.

```text
/newbot
```

Follow the on-screen instructions.

BotFather will generate:

- Bot Name
- Bot Username
- Bot Token

---

# 🔑 Bot Token

Example:

```cpp
#define BOT_TOKEN "YOUR_BOT_TOKEN"
```

Replace the placeholder in the ESP32 firmware with the token generated by BotFather.

---

# 🆔 Obtaining the Chat ID

After creating the bot:

1. Start a conversation with your bot.
2. Send any message (for example, **Hello**).
3. Retrieve your Chat ID using a Telegram Chat ID service or the Telegram Bot API.
4. Copy the Chat ID.

Example:

```cpp
#define CHAT_ID "YOUR_CHAT_ID"
```

Replace the placeholder inside the ESP32 firmware.

---

# 💬 Supported Telegram Commands

The firmware supports the following commands.

| Command | Description |
|:---------|:------------|
| `/status` | Displays the current motor status |
| `/auto` | Enables Automatic Irrigation Mode |
| `/manual_on` | Turns the irrigation pump ON |
| `/manual_off` | Turns the irrigation pump OFF |

---

# 📩 Automatic Notifications

The ESP32 automatically sends Telegram notifications for important events.

Notifications include:

- ESP32 Startup
- Sensor Updates
- Motor Status Changes
- Automatic Irrigation Events
- Rain Detection
- Boot Status Messages

This allows users to stay informed without continuously checking the dashboard.

---

# 🌍 Complete Communication Workflow

The complete communication sequence is illustrated below.

```text
Sensors
     │
     ▼
STM32 Blue Pill
     │
UART Communication
     │
     ▼
ESP32
     │
Wi-Fi
     │
     ├───────────────┐
     ▼               ▼
ThingSpeak      Telegram Bot
     │               │
     └───────┬───────┘
             ▼
        Remote User
```

---

# 🔄 System Operation Sequence

The system continuously performs the following operations.

1. STM32 acquires sensor data.
2. Sensor values are processed.
3. Automatic irrigation logic is executed.
4. Relay status is updated.
5. Processed data is transmitted to the ESP32 via UART.
6. ESP32 receives the data packet.
7. ESP32 uploads the latest readings to ThingSpeak.
8. ESP32 checks for incoming Telegram commands.
9. Telegram notifications are generated when required.
10. The monitoring cycle repeats continuously.

---

> [!TIP]
> Before uploading the ESP32 firmware, verify that the **Wi-Fi credentials**, **ThingSpeak Write API Key**, **Telegram Bot Token**, and **Telegram Chat ID** have been correctly updated. Incorrect credentials will prevent cloud communication and remote monitoring features from functioning properly.

# ⚙️ System Operation

The **Irrigation Monitoring Using STM32 BluePill & ESP32** system is designed around a dual-microcontroller architecture, where each controller performs a dedicated task to ensure reliable operation, accurate sensor monitoring, and uninterrupted IoT communication.

The **STM32 Blue Pill** functions as the primary embedded controller, continuously monitoring environmental parameters and controlling the irrigation pump based on predefined conditions. The **ESP32** operates as an IoT gateway, receiving processed sensor data from the STM32 through UART communication and handling all internet-related operations, including cloud connectivity, Telegram Bot communication, and remote user interaction.

This separation of responsibilities improves overall system stability by ensuring that internet communication does not interfere with real-time irrigation control.

---

# 🔄 Complete System Workflow

The complete operation of the irrigation monitoring system follows the sequence illustrated below.

```text
                   Power ON
                      │
                      ▼
          Initialize STM32 Blue Pill
                      │
                      ▼
             Initialize ESP32
                      │
                      ▼
         Connect ESP32 to Wi-Fi Network
                      │
                      ▼
         Read Soil Moisture Sensor
                      │
                      ▼
     Read Temperature & Humidity (DHT11)
                      │
                      ▼
            Read Rain Sensor
                      │
                      ▼
      STM32 Processes Sensor Values
                      │
                      ▼
      Execute Irrigation Control Logic
                      │
                      ▼
        Control Water Pump Relay
                      │
                      ▼
      Send Sensor Data through UART
                      │
                      ▼
        ESP32 Receives UART Packet
                      │
          ┌───────────┴───────────┐
          ▼                       ▼
 Upload Data to ThingSpeak   Check Telegram Commands
          │                       │
          ▼                       ▼
 Update Cloud Dashboard    Execute Remote Commands
          │                       │
          └───────────┬───────────┘
                      ▼
          Send Telegram Notifications
                      │
                      ▼
             Repeat Continuously
```

---

# 🌱 Sensor Monitoring

The STM32 Blue Pill continuously monitors all connected environmental sensors.

The monitored parameters include:

| Sensor | Measured Parameter |
|:--------|:-------------------|
| Soil Moisture Sensor | Soil Moisture Percentage |
| DHT11 Sensor | Ambient Temperature |
| DHT11 Sensor | Relative Humidity |
| Rain Sensor | Rain Detection |

Sensor readings are refreshed continuously, allowing the irrigation system to respond quickly to changing environmental conditions.

---

# 🌿 Soil Moisture Measurement

The soil moisture sensor provides an analog voltage proportional to the moisture content of the soil.

The STM32 reads this analog value using its ADC and converts it into a percentage through sensor calibration.

```text
Raw ADC Value
        │
        ▼
Calibration
        │
        ▼
Soil Moisture Percentage
        │
        ▼
Used by Irrigation Algorithm
```

The moisture percentage is later transmitted to the ESP32 for cloud monitoring.

---

# 🌡 Temperature and Humidity Monitoring

Ambient temperature and relative humidity are measured using the **DHT11** sensor.

These environmental parameters are transmitted to the cloud together with soil moisture readings, allowing users to monitor the overall condition of the irrigation environment.

The collected data also assists in evaluating long-term environmental changes affecting irrigation performance.

---

# 🌧 Rain Detection

The rain sensor continuously monitors rainfall conditions.

Rain detection has the highest priority within the irrigation algorithm.

Whenever rainfall is detected:

- Irrigation is immediately stopped.
- Relay output is switched OFF.
- Updated status is transmitted to the ESP32.
- ThingSpeak dashboard is updated.
- Telegram notification is generated.

This prevents unnecessary irrigation and improves water conservation.

---

# 🚰 Automatic Irrigation Logic

The STM32 Blue Pill independently controls the irrigation pump according to environmental conditions.

The implemented decision logic is summarized below.

| Condition | Pump Status |
|:----------|:-----------:|
| Rain Detected | OFF |
| Soil Moisture > 60% | ON |
| Soil Moisture < 40% | OFF |
| Soil Moisture Between 40% and 60% | Maintain Previous State |

This control strategy minimizes unnecessary switching while maintaining appropriate soil moisture levels.

> [!NOTE]
> The irrigation logic shown above is identical to the firmware implementation included in this repository.

---

# ⚡ Relay Control

The relay module operates using **Active-Low Logic**.

| Relay Input | Pump Status |
|:------------|:-----------:|
| LOW | ON |
| HIGH | OFF |

This logic is implemented directly within both firmware programs to ensure consistent operation.

---

# 📡 UART Communication

After processing sensor data, the STM32 prepares a comma-separated data packet and transmits it to the ESP32 through UART communication.

Typical packet format:

```text
Moisture,Temperature,Humidity,Rain
```

Example:

```text
68,29,71,0
```

| Field | Description |
|:------|:------------|
| 68 | Soil Moisture (%) |
| 29 | Temperature (°C) |
| 71 | Humidity (%) |
| 0 | Rain Status |

The ESP32 continuously monitors the UART interface and immediately processes every received packet.

---

# ☁️ Cloud Data Upload

After receiving a valid UART packet, the ESP32 uploads the latest sensor values to ThingSpeak.

Each upload contains:

- Soil Moisture
- Motor Status
- Temperature
- Humidity
- Rain Status

The cloud dashboard is updated automatically, allowing users to monitor the irrigation system remotely in real time.

---

# 🤖 Telegram Communication

The ESP32 periodically checks the Telegram Bot for new user commands while simultaneously sending automatic notifications whenever significant system events occur.

Supported remote operations include:

- Enable Automatic Mode
- Enable Manual Mode
- Turn Pump ON
- Turn Pump OFF
- Check Motor Status

Automatic notifications are generated whenever:

- The ESP32 starts successfully.
- Sensor values change.
- Pump status changes.
- Rain is detected.
- No sensor data is received during startup.

---

# 📈 Real-Time Data Flow

The following diagram illustrates the complete movement of information throughout the irrigation monitoring system.

```text
               Soil Moisture Sensor
                        │
                        ▼
                  DHT11 Sensor
                        │
                        ▼
                  Rain Sensor
                        │
                        ▼
            STM32 Blue Pill Controller
                        │
          Sensor Processing & Decision
                        │
                        ▼
               UART Communication
                        │
                        ▼
                     ESP32
                        │
              Wi-Fi Communication
                        │
        ┌───────────────┴───────────────┐
        ▼                               ▼
  ThingSpeak Cloud                Telegram Bot
        │                               │
        └───────────────┬───────────────┘
                        ▼
                  Remote User
```

---

# 🧪 System Validation

The following checks were performed to verify the functionality of the complete system.

| Test | Expected Result |
|:-----|:----------------|
| Soil Moisture Reading | Successful |
| Temperature Reading | Successful |
| Humidity Reading | Successful |
| Rain Detection | Successful |
| Relay Operation | Successful |
| Automatic Irrigation | Successful |
| UART Communication | Successful |
| Wi-Fi Connectivity | Successful |
| ThingSpeak Upload | Successful |
| Telegram Notification | Successful |
| Manual Pump Control | Successful |
| Cloud Monitoring | Successful |

---

# 🎯 Advantages of the Proposed System

The developed irrigation monitoring system offers several practical advantages.

- Reliable dual-microcontroller architecture.
- Stable real-time embedded processing.
- Dedicated IoT communication through ESP32.
- Automatic irrigation based on environmental conditions.
- Reduced water wastage through rain-aware control.
- Remote monitoring from anywhere using the internet.
- Cloud-based historical data storage.
- Telegram-based remote control and notifications.
- Modular firmware for future expansion.
- Low-cost implementation using readily available hardware.

---

# 🚀 Future Scope

The modular design of this project allows it to be extended with additional hardware and software features.

Potential future enhancements include:

- Blynk Mobile Application Integration
- MQTT-Based Communication
- Firebase Cloud Integration
- OLED or TFT Display
- Water Level Monitoring
- Water Flow Sensor
- Soil pH Measurement
- Electrical Conductivity (EC) Sensor
- Solar-Powered Irrigation
- Battery Backup System
- Multi-Zone Irrigation Control
- LoRa-Based Long-Range Communication
- AI-Based Irrigation Prediction
- Weather Forecast Integration
- Mobile Dashboard Application
- Automatic Fertigation System

> [!TIP]
> Since the sensing, control, and communication modules are separated into independent firmware components, additional sensors, cloud platforms, or communication technologies can be integrated with minimal modification to the existing system architecture.

# 📄 License

This project is licensed under the **MIT License**.

You are free to use, modify, distribute, and build upon this project for both personal and commercial purposes, provided that the original copyright and license notice are included.

For complete license information, see the **LICENSE** file included in this repository.

---

# 🤝 Contributing

Contributions are always welcome.

If you would like to improve this project, you can contribute by:

- Fixing bugs
- Improving documentation
- Optimizing firmware
- Adding new hardware support
- Enhancing cloud integration
- Implementing additional communication protocols
- Adding new sensors and automation features

### Contribution Workflow

1. Fork this repository.
2. Create a new feature branch.

```bash
git checkout -b feature/NewFeature
```

3. Commit your changes.

```bash
git commit -m "Added new feature"
```

4. Push your branch.

```bash
git push origin feature/NewFeature
```

5. Open a Pull Request.

---

# 🐞 Reporting Issues

If you encounter any bugs or unexpected behavior, please create an issue in the GitHub repository.

When submitting an issue, include:

- Hardware configuration
- Board version
- Arduino IDE version
- Library versions
- Serial Monitor output
- Error messages
- Steps to reproduce the problem

Providing complete information helps identify and resolve issues more efficiently.

---

# 📂 Repository Structure

```text
IRRIGATION-MONITORING-USING-STM32-BLUEPILL-ESP32
│
├── Firmware
│   ├── STM32_BluePill
│   │   └── STM32_BluePill.ino
│   │
│   └── ESP32
│       └── ESP32.ino
│
├── Circuit_Diagram
│   └── Circuit_Diagram.png
│
├── Project_Report
│   └── Project_Report.pdf
│
├── Images
│
├── LICENSE
├── CONTRIBUTING.md
├── SECURITY.md
└── README.md
```

---

# 📚 Libraries Used

## STM32 Blue Pill

- DHT Sensor Library

---

## ESP32

- WiFi
- HTTPClient
- WiFiClientSecure
- UniversalTelegramBot

Install all required libraries before compiling the firmware.

---

# 🛠 Development Environment

| Software | Version |
|:---------|:--------|
| Arduino IDE | 2.x Recommended |
| STM32 Arduino Core | Latest Stable |
| ESP32 Board Package | Latest Stable |

---

# 🧩 Hardware Specifications

| Component | Description |
|:----------|:------------|
| Main Controller | STM32F103C8T6 Blue Pill |
| IoT Controller | ESP32 Development Board |
| Soil Moisture Sensor | Analog |
| Temperature Sensor | DHT11 |
| Humidity Sensor | DHT11 |
| Rain Sensor | Analog |
| Relay Module | Single Channel (Active-Low) |
| Water Pump | DC Pump |
| Power Supply | 5V DC |

---

# 💡 Key Highlights

- Dual Microcontroller Architecture
- Real-Time Sensor Monitoring
- Automatic Irrigation Control
- UART-Based Controller Communication
- ThingSpeak Cloud Integration
- Telegram Bot Remote Control
- Manual & Automatic Operating Modes
- Cloud Data Logging
- Live Sensor Visualization
- Internet-Based Monitoring
- Modular Firmware Design
- Beginner-Friendly Project Structure

---

# 👨‍💻 Author

**ShivsFoundry**

Embedded Systems • IoT • Robotics • Electronics • Open Source Hardware

GitHub Profile:

```text
https://github.com/ShivsFoundry
```

---

# ⭐ Support the Project

If you found this project useful, consider supporting it by:

- ⭐ Starring this repository
- 🍴 Forking the project
- 🛠 Contributing improvements
- 🐞 Reporting issues
- 💬 Sharing feedback
- 📢 Recommending it to others

Your support encourages the continued development of open-source embedded systems and IoT projects.

---

# 📖 Citation

If you use this project for academic work, research, or educational purposes, please cite this repository appropriately.

```text
ShivsFoundry.
IRRIGATION MONITORING USING STM32 BLUEPILL & ESP32.
GitHub Repository.
```

---

# 🙏 Acknowledgements

This project was successfully developed using the following open-source technologies and platforms.

- STM32 Arduino Core
- ESP32 Arduino Framework
- ThingSpeak IoT Platform
- Telegram Bot API
- Arduino IDE
- DHT Sensor Library
- UniversalTelegramBot Library
- HTTPClient Library
- WiFi Library

Special thanks to the open-source community for providing the libraries, tools, and documentation that made this project possible.

---

# 📬 Contact

For project discussions, suggestions, collaborations, or technical queries, feel free to reach out through GitHub.

**GitHub:** `https://github.com/ShivsFoundry`

---

<div align="center">

## ⭐ If you found this project helpful, don't forget to Star the repository!

**Made with ❤️ by ShivsFoundry**

*Building Reliable Embedded Systems & IoT Solutions*

</div>
