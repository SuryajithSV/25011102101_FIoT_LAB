# Fundamentals of IoT (FIoT) Laboratory Portfolio

**Repository:** `25011102101_FIoT_LAB`  
**Student Name:** Suryajith S V  
**Registration Number:** 25011102101  
**Degree & Branch:** B.Tech CSE (IoT - B)  
**Institution:** Shiv Nadar University, Chennai — Department of Computer Science & Engineering  
**Course:** 25CS2741 Fundamentals of Internet of Things + Lab  

---

## 1. Overview
This repository contains the complete experimental implementations, circuit schematics, register configurations, source code, and comprehensive documentation for the Internet of Things (IoT) Laboratory course evaluations. 

### Coursework Adherence & Submission Compliance
- **Repository Naming:** Named strictly as `25011102101_FIoT_LAB` based on student registration number `25011102101` (last three digits: `101`).
- **Circuit Diagrams:** Every individual task README includes its own embedded high-resolution SVG and PNG schematic with verified pin connections.
- **CAT Numbering Structure:** Organizes all experiments according to the Continuous Assessment Test (CAT) evaluation sheets and coursework Hands-on Exercises:
  - **8051 Architecture:** CAT 2 through CAT 7 (Weeks 2 to 7).
  - **STM32 Architecture:** CAT 8 through CAT 13 (Weeks 8 to 13).
  - **CAT 10 Continuation:** Wemos ESP8266 AT modem and HTTP micro-server tasks are unified sequentially as `TASK10A` through `TASK10E` under `STM32/CAT10/`. 

The laboratory syllabus is structured across two primary computing tiers:
1. **8-bit Classical Embedded Architecture:** AT89S52 (8051 Core) bare-metal register programming, timing loops, peripheral drivers (UART, LCD, Keypad, Stepper Motor), and hardware interrupts using Keil C51.
2. **32-bit High-Performance ARM Architecture:** STMicroelectronics STM32F103C8T6 (Blue Pill Cortex-M3) and STM32F401RET6 (Nucleo-64 Cortex-M4) with STM32CubeMX hardware abstraction layer (HAL), Wi-Fi internet connectivity (ESP8266 / Wemos D1 Mini), environmental sensing (Bosch Sensortec BME280 via I²C), HTTP micro-servers, and cloud MQTT telemetry with Node-RED analytics.

---

## 2. Hardware Platforms

| Platform Identifier | Target Microcontroller | Architecture | Operating Voltage | Clock Source | Primary Peripherals / Drivers |
|---|---|---|---|---|---|
| **8051 Tier** | Microchip / Atmel AT89S52 | 8-bit 8051 CISC | 5.0V DC | 11.0592 MHz Quartz Crystal | GPIOs, Timers 0/1, UART (9600-8-N-1), HD44780 LCD, 4x4 Keypad, ULN2003 Stepper |
| **STM32 Tier 1** | STM32F103C8T6 (Blue Pill) | 32-bit ARM Cortex-M3 | 3.3V DC | 72 MHz (8 MHz HSE + PLL x9) | GPIO (PC13 LED, PA0 Button), USART1, SysTick |
| **STM32 Tier 2** | STM32F401RET6 (NUCLEO-F401RE) | 32-bit ARM Cortex-M4 with FPU | 3.3V DC | 84 MHz (HSI / HSE + PLL) | GPIO (PA5 LD2, PC13 B1), USART2, I2C1 (BME280), ESP8266 Modem |
| **Wi-Fi Tier** | Wemos D1 Mini (ESP8266-12F) | 32-bit Tensilica L106 | 3.3V / 5V DC | 80 / 160 MHz | AT Command Interpreter, TCP Server (Port 80), MQTT Client (Port 1883) |
| **Sensor Tier** | Bosch Sensortec BME280 | I²C Environmental Sensor | 3.3V DC | 100 kHz Standard I²C Bus | Temperature, Barometric Pressure, Relative Humidity |

---

## 3. Repository Structure

The repository is unified under two core platform directories (`8051` and `STM32`). Every experiment is organized into dedicated task subfolders containing its own standalone `README.md`, embedded vector and raster circuit schematics (`circuit.svg`, `circuit.png`), pin tables, clock configurations, pseudocode, and source code files:

```text
25011102101_FIoT_LAB/
├── .gitignore
├── README.md
│
├── 8051/
│   ├── CAT2/                                  # 8051 Tool Chain Setup & Bare-Metal LED Blink
│   │   ├── TASK1_Hardware_Bring_Up/           # Board Bring-Up, Power Rails & ISP Verification
│   │   ├── TASK2_Bare_Metal_LED_Blink/         # Port 1 Pin 0 (P1.0) 1 Hz LED Blink (Keil Project)
│   │   └── TASK3_Custom_Delay_Library/        # Calibrated 11.0592 MHz Millisecond Delay Library
│   ├── CAT3/                                  # Timer-Based LED Pattern Generator & Button Controller
│   │   ├── TASKA_Running_LED/                 # Mode 1: 4-LED Circular Chase Sequence
│   │   ├── TASKB_Binary_Counter/              # Mode 2: 4-Bit Binary Counter (0 to 15)
│   │   ├── TASKC_Alternating_Pattern/         # Mode 3: Alternating Pattern (1010 <-> 0101)
│   │   └── TASKD_All_LED_Flash/               # Mode 4: All-LED Synchronous Flash (1111 <-> 0000)
│   ├── CAT4/                                  # HMI: Matrix Keypad, LEDs, & 7-Segment Display
│   │   ├── TASKA_Keypad_Seven_Segment/        # 4x4 Keypad Row-Column Scan & 7-Segment Feedback
│   │   └── TASKB_LED_Mode_Controller/         # 10-Key Function Dispatcher to Operating Modes
│   ├── CAT5/                                  # Hardware Timer Timing: PWM, Pulses & Stepper Motor
│   │   ├── TASK1_Timer_Periodic_Interrupt/    # Timer 0 Mode 1 1-Second Timebase (TH0=0xFC, TL0=0x66)
│   │   ├── TASK2A_LED_Fading_PWM/             # Software PWM LED Fading (500 Hz, 0% to 100%)
│   │   ├── TASK2B_Variable_Frequency_Pulse/   # Waveform Synthesis (100 Hz to 5 kHz Square Waves)
│   │   └── TASK3_Stepper_Motor_Control/       # ULN2003 Stepper Commutation (1000->0100->0010->0001)
│   ├── CAT6/                                  # UART Driver & Serial Debugging
│   │   ├── TASKA_UART_Transmit/               # 9600-8-N-1 String Transmitter ("Hello from 8051")
│   │   └── TASKB_UART_Echo/                   # Full-Duplex Keystroke Echo Terminal
│   └── CAT7/                                  # 16x2 LCD Driver Development & Display Control
│       ├── TASK7A_LCD_Init_Display/           # 4-Bit HD44780 LCD Driver & Dual-Row Display
│       ├── TASK7B_Cursor_Dynamic_Update/      # DDRAM Addressing (`lcd_goto`) & Numeric Counter
│       └── TASK7C_Keypad_Character_Movement/  # 2D Interactive Cursor Navigation (Keys 2, 8, 4, 6)
│
└── STM32/
    ├── CAT8/                                  # STM32 GPIO Bring-Up & Switch-Controlled LED
    │   ├── TASK8A_GPIO_IO/                    # Direct Switch Mirror on PC13 LED (CubeMX + Keil)
    │   ├── TASK8B_Event_Debounce/             # Software Contact Bounce Suppression & Edge Toggle
    │   └── TASK8C_Short_Long_Press/           # Non-Blocking HAL_GetTick() Temporal Classifier (<1s vs >=1s)
    ├── CAT9/                                  # STM32 UART Command Controlled LED
    │   ├── TASK9A_Basic_UART_Communication/   # USART1 115200-8-N-1 Character Transmit & Echo
    │   └── TASK9B_String_Command_Parser/      # Interactive CLI Parser ("LED ON", "LED OFF", "LED TOGGLE")
    ├── CAT10/                                 # STM32-Wemos Wi-Fi Modem Interface / HTTP Server
    │   ├── TASK10A_UART_AT_Communication/     # STM32 to ESP8266 Modem Bring-Up (`AT` -> `OK`)
    │   ├── TASK10B_AT_Command_Exploration/    # Station Mode, Firmware Query & AP Scanning
    │   ├── TASK10C_WiFi_Station_TCP_Server/   # AP Association & Multi-Connection Port 80 Server
    │   ├── TASK10D_HTTP_Response_Handling/    # `+IPD` Parser & 2-Step CIPSEND HTTP 200 OK Delivery
    │   └── TASK10E_NodeRED_HTTP_Client/       # Node-RED Automated HTTP GET Ingestion Pipeline
    ├── CAT11/                                 # STM32F401RE Cortex-M4 GPIO & User Input
    │   ├── TASK1_Onboard_LED_BringUp/         # NUCLEO-F401RE PA5 (LD2) 84 MHz Blink (CubeMX + Keil)
    │   ├── TASK2_Switch_State_Remembrance/    # PC13 (B1) Button with Latched State Memory
    │   └── TASK3_Short_Long_Press_Detection/  # Asynchronous Short vs Long Press State Machine
    ├── CAT12/                                 # BME280 Environmental Sensing & HTTP Analytics
    │   ├── TASK12A_BME280_I2C_Driver/         # I2C1 Bosch Sensortec API Integration & Compensation
    │   ├── TASK12B_Dynamic_JSON_Payload/      # Floating-Point JSON Telemetry Formatter
    │   └── TASK12C_HTTP_Response_NodeRED/     # Live JSON Web Service & Node-RED Statistical Analytics
    └── CAT13/                                 # BME280 Cloud MQTT Telemetry & Dashboard
        ├── TASK13A_MQTT_Broker_Connection/    # ESPLib Driver & TCP Session with broker.emqx.io:1883
        ├── TASK13B_MQTT_Publish_Telemetry/    # Periodic QoS 0 Publishing to `stm32/test/data`
        ├── TASK13C_MQTT_Subscribe_Control/    # Asynchronous `IOT` Topic Subscription & SysTick Timer
        └── TASK13D_NodeRED_MQTT_Dashboard/    # Real-Time Gauge, Chart & Control Flow
```

---

## 4. Experiment Summary Matrix

| Category | Lab Code | Experiment Title | Subdivisions | Primary Peripherals / Protocols | Documentation |
|---|---|---|---|---|---|
| **8051** | CAT 2 | Tool Chain Setup & LED Blink | 3 Tasks (Bring-Up, Blink, Delay) | P1.0 LED, ISP Header, Reset Network | [Task 2A README](8051/CAT2/TASK2_Bare_Metal_LED_Blink/README.md) |
| **8051** | CAT 3 | LED Pattern & Button Interrupt | 4 Modes (Chase, Count, Alt, Flash) | P1.0-P1.3 LEDs, P3.2 (/INT0) Switch | [Task A README](8051/CAT3/TASKA_Running_LED/README.md) |
| **8051** | CAT 4 | HMI: Keypad & 7-Segment | 2 Tasks (Keypad/7-Seg, Modes) | Port 2 Keypad, Port 0 7-Segment, P1 LEDs | [Task A README](8051/CAT4/TASKA_Keypad_Seven_Segment/README.md) |
| **8051** | CAT 5 | Hardware Timers & PWM Fading | 4 Tasks (Timebase, PWM, Pulse, Stepper) | Timer 0, Timer 1, ULN2003 Stepper Motor | [Task 1 README](8051/CAT5/TASK1_Timer_Periodic_Interrupt/README.md) |
| **8051** | CAT 6 | UART Driver & Serial Debug | 2 Tasks (Transmit, Echo) | P3.0/P3.1 UART (9600-8-N-1), USB-TTL | [Task A README](8051/CAT6/TASKA_UART_Transmit/README.md) |
| **8051** | CAT 7 | 16x2 LCD Driver Development | 3 Tasks (Init, DDRAM Cursor, Nav) | Port 2 4-Bit LCD, Port 1 Matrix Keypad | [Task 7A README](8051/CAT7/TASK7A_LCD_Init_Display/README.md) |
| **STM32** | CAT 8 | GPIO Bring-Up & Switch LED | 3 Tasks (Direct, Debounce, Duration) | PC13 LED, PA0 Button, HAL_GetTick() | [Task 8A README](STM32/CAT8/TASK8A_GPIO_IO/README.md) |
| **STM32** | CAT 9 | UART Command Controlled LED | 2 Tasks (Echo, CLI Parser) | USART1 (115200-8-N-1), PC13 LED | [Task 9A README](STM32/CAT9/TASK9A_Basic_UART_Communication/README.md) |
| **STM32** | CAT 10 | Wi-Fi AT Modem & HTTP Server | 5 Tasks (AT, Scan, TCP, HTTP, Node-RED) | USART2, ESP8266 Wemos D1, Port 80 HTTP | [Task 10D README](STM32/CAT10/TASK10D_HTTP_Response_Handling/README.md) |
| **STM32** | CAT 11 | Cortex-M4 GPIO & User Input | 3 Tasks (Bring-Up, Memory, Classifier) | NUCLEO-F401RE PA5 (LD2), PC13 (B1) | [Task 1 README](STM32/CAT11/TASK1_Onboard_LED_BringUp/README.md) |
| **STM32** | CAT 12 | BME280 Sensing & HTTP Analytics | 3 Tasks (I2C Driver, JSON, Analytics) | I2C1 (PB8/PB9), Bosch API, Node-RED | [Task 12A README](STM32/CAT12/TASK12A_BME280_I2C_Driver/README.md) |
| **STM32** | CAT 13 | BME280 MQTT Cloud Telemetry | 4 Tasks (Connect, Publish, Subscribe, Dash) | USART2, ESPLib, broker.emqx.io, Node-RED | [Task 13A README](STM32/CAT13/TASK13A_MQTT_Broker_Connection/README.md) |

---

## 5. Software Toolchains and IDEs

1. **Keil µVision C51:**
   - Compiler for Atmel AT89S52 bare-metal C applications.
   - Outputs Intel HEX (`.hex`) target firmware for ISP flash downloading.
2. **STM32CubeMX:**
   - Graphical peripheral configuration, pinout mapping, and clock tree synthesis.
   - Generates project definitions (`.ioc`) and HAL peripheral driver scaffolding.
3. **Keil MDK-ARM (µVision5):**
   - Professional IDE for STM32 ARM Cortex-M3/M4 compilation and hardware debugging.
   - Integrated ST-LINK SWD driver for flash programming and live watch expressions.
4. **Visual Studio Code:**
   - Modern editor equipped with C/C++, Cortex-Debug, GitLens, and serial monitor extensions.
5. **Node-RED:**
   - Low-code flow programming environment for automated HTTP ingestion and real-time MQTT dashboards (`localhost:1880`).

---

## 6. Implementation & Verification Status

All 38 tasks across 8051 and STM32 platforms have been systematically verified and tested:

- **Hardware Validated Keil Projects:**
  - `8051/CAT2/TASK2_Bare_Metal_LED_Blink`: Compiled with Keil C51, verified on AT89S52 hardware. Complete Keil project file (`LED_BLINK.uvproj`), assembly startup (`STARTUP.A51`), and C source code preserved.
  - `STM32/CAT8/TASK8A_GPIO_IO`: Generated via STM32CubeMX for STM32F103C8T6, compiled with Keil MDK-ARM, verified on STM32 Blue Pill. Complete `.ioc`, `Core/`, `Drivers/`, and `MDK-ARM/` preserved.
  - `STM32/CAT11/TASK1_Onboard_LED_BringUp`: Generated via STM32CubeMX for STM32F401RET6, compiled with Keil MDK-ARM, verified on NUCLEO-F401RE. Complete `.ioc`, `Core/`, `Drivers/`, and `MDK-ARM/` preserved.
- **Embedded C Compiler Verification:**
  - **STM32 C Files:** All 17 user source files compiled with `armclang` (Arm Compiler for Embedded 6.24, MDK-ARM 5.43) with 0 errors.
  - **8051 C Files:** All 18 8051 C files verified against standard C51 / ISO C99 standards with 0 syntax errors.
  - **Circuit Schematics:** Clean, high-resolution SVG and PNG diagrams generated for every task with clear MCU pinouts, peripheral schematics, and zero overlapping labels.
- **Full-Stack IoT Flows:**
  - Complete Bosch Sensortec BME280 I²C sensor driver and telemetry serializer (`CAT12`).
  - Modular `ESPLib` ESP8266 driver for cloud MQTT broker connections (`broker.emqx.io:1883`) and topic pub/sub (`CAT13`).
  - Standalone Node-RED JSON flow configurations ready for import (`CAT10E`, `CAT12C`, `CAT13D`).
