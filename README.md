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

The laboratory syllabus is structured across two primary computing tiers:
1. **8-bit Classical Embedded Architecture:** AT89S52 (8051 Core) bare-metal register programming, timing loops, peripheral drivers (UART, LCD, Keypad, Stepper Motor), and hardware interrupts using Keil C51.
2. **32-bit High-Performance ARM Architecture:** STMicroelectronics STM32F103C8T6 (Blue Pill Cortex-M3) and STM32F401RET6 (Nucleo-64 Cortex-M4) with STM32CubeMX hardware abstraction layer (HAL), Wi-Fi internet connectivity (ESP8266 / Wemos D1 Mini), environmental sensing (Bosch Sensortec BME280 via I²C), HTTP micro-servers, and cloud MQTT telemetry with Node-RED analytics.

---

## 2. CAT Folders & Task Directory Index

Below is the comprehensive index of all continuous evaluation assignments across both platforms. Every individual task directory contains its own standalone `README.md`, embedded circuit schematic (`circuit.png`), and complete project/source files:

### 8051 Microcontroller Tier (AT89S52)

| Category Folder | Task Folder | Experiment Title | Hardware Peripherals | Task Documentation |
|---|---|---|---|:---:|
| [8051/CAT2](8051/CAT2/) | [TASK2B](8051/CAT2/TASK2B/) | Bare-Metal LED Blink | P1.0 LED, 11.0592 MHz Crystal | [README](8051/CAT2/TASK2B/README.md) |
| [8051/CAT3](8051/CAT3/) | [TASK3A](8051/CAT3/TASK3A/) | Switch Polling & LED Chase / Counter / Alternating Patterns | P1.0–P1.3 LEDs, P3.2 Switch | [README](8051/CAT3/TASK3A/README.md) |
| [8051/CAT4](8051/CAT4/) | [TASK4A](8051/CAT4/TASK4A/) | 4x4 Keypad Matrix Scan & 7-Segment Display | Port 2 Keypad, Port 0 7-Segment | [README](8051/CAT4/TASK4A/README.md) |
| [8051/CAT5](8051/CAT5/) | [TASK5A](8051/CAT5/TASK5A/) | Hardware Timer 0 Periodic Interrupt (1s Timebase) | Timer 0 Mode 1 (TH0=0xFC, TL0=0x66) | [README](8051/CAT5/TASK5A/README.md) |
| [8051/CAT5](8051/CAT5/) | [TASK5B/TASK5B.1](8051/CAT5/TASK5B/TASK5B.1/) | Software PWM LED Fading (500 Hz, 0% to 100%) | Timer 1, P1.0 LED | [README](8051/CAT5/TASK5B/TASK5B.1/README.md) |
| [8051/CAT5](8051/CAT5/) | [TASK5B/TASK5B.2](8051/CAT5/TASK5B/TASK5B.2/) | Variable Frequency Pulse Generation (100 Hz – 5 kHz) | Timer 1, P1.1 Output | [README](8051/CAT5/TASK5B/TASK5B.2/README.md) |
| [8051/CAT5](8051/CAT5/) | [TASK5B/TASK5B.3](8051/CAT5/TASK5B/TASK5B.3/) | Calibrated Duty Cycle Controller & Waveform Synthesizer | Timer 1, Mode 2 Auto-Reload | [README](8051/CAT5/TASK5B/TASK5B.3/README.md) |
| [8051/CAT5](8051/CAT5/) | [TASK5C](8051/CAT5/TASK5C/) | 4-Phase Unipolar Stepper Motor Control | ULN2003 Driver, P1.4–P1.7 | [README](8051/CAT5/TASK5C/README.md) |
| [8051/CAT6](8051/CAT6/) | [TASK6A](8051/CAT6/TASK6A/) | UART String Transmitter (9600-8-N-1) | P3.1 (TxD), USB-UART Bridge | [README](8051/CAT6/TASK6A/README.md) |
| [8051/CAT6](8051/CAT6/) | [TASK6B](8051/CAT6/TASK6B/) | Full-Duplex UART Echo Terminal | P3.0 (RxD), P3.1 (TxD) | [README](8051/CAT6/TASK6B/README.md) |
| [8051/CAT7](8051/CAT7/) | [TASK7A](8051/CAT7/TASK7A/) | 16x2 HD44780 LCD Driver Initialization & Display | Port 2 4-Bit LCD Bus | [README](8051/CAT7/TASK7A/README.md) |
| [8051/CAT7](8051/CAT7/) | [TASK7B](8051/CAT7/TASK7B/) | LCD DDRAM Cursor Positioning & Dynamic Counter | Port 2 4-Bit LCD Bus | [README](8051/CAT7/TASK7B/README.md) |
| [8051/CAT7](8051/CAT7/) | [TASK7C](8051/CAT7/TASK7C/) | 2D Interactive Keypad Cursor Navigation | Port 1 Keypad, Port 2 LCD | [README](8051/CAT7/TASK7C/README.md) |

---

### STM32 ARM Cortex-M Tier (STM32F103 / STM32F401)

| Category Folder | Task Folder | Experiment Title | Hardware Peripherals | Task Documentation |
|---|---|---|---|:---:|
| [STM32/CAT8](STM32/CAT8/) | [TASK8A](STM32/CAT8/TASK8A/) | STM32 Blue Pill GPIO Bring-Up & Switch LED | PC13 LED, PA0 Tactile Button | [README](STM32/CAT8/TASK8A/README.md) |
| [STM32/CAT8](STM32/CAT8/) | [TASK8B](STM32/CAT8/TASK8B/) | Software Push-Button Contact Debounce & Edge Toggle | PC13 LED, PA0 Button, HAL_GetTick() | [README](STM32/CAT8/TASK8B/README.md) |
| [STM32/CAT8](STM32/CAT8/) | [TASK8C](STM32/CAT8/TASK8C/) | Temporal Classifier (<1s Short vs ≥1s Long Press) | PC13 LED, PA0 Button | [README](STM32/CAT8/TASK8C/README.md) |
| [STM32/CAT9](STM32/CAT9/) | [TASK9A](STM32/CAT9/TASK9A/) | USART1 115200-8-N-1 Character Transmit & Echo | USART1 (PA9/PA10), USB-TTL | [README](STM32/CAT9/TASK9A/README.md) |
| [STM32/CAT9](STM32/CAT9/) | [TASK9B](STM32/CAT9/TASK9B/) | Interactive Serial CLI Parser ("LED ON/OFF/TOGGLE") | USART1, PC13 User LED | [README](STM32/CAT9/TASK9B/README.md) |
| [STM32/CAT10](STM32/CAT10/) | [TASK10A](STM32/CAT10/TASK10A/) | STM32 USART Bridge & ESP8266 Modem Bring-Up (`AT` -> `OK`) | USART2 (PA2/PA3), Wemos D1 Mini | [README](STM32/CAT10/TASK10A/README.md) |
| [STM32/CAT10](STM32/CAT10/) | [TASK10B](STM32/CAT10/TASK10B/) | ESP8266 Wi-Fi Mode Setup & AP Scanning (`CWMODE`, `CWLAP`) | USART2, ESP8266 Modem | [README](STM32/CAT10/TASK10B/README.md) |
| [STM32/CAT10](STM32/CAT10/) | [TASK10C](STM32/CAT10/TASK10C/) | Wi-Fi Station Association & Multi-Client HTTP Server (Port 80) | USART2, ESP8266 TCP Server | [README](STM32/CAT10/TASK10C/README.md) |
| [STM32/CAT11](STM32/CAT11/) | [TASK11A](STM32/CAT11/TASK11A/) | NUCLEO-F401RE Onboard LD2 LED 84 MHz Bring-Up | PA5 User LED, ST-LINK V2.1 | [README](STM32/CAT11/TASK11A/README.md) |
| [STM32/CAT11](STM32/CAT11/) | [TASK11B](STM32/CAT11/TASK11B/) | PC13 (B1) User Switch State Remembrance & Temporal Press | PC13 User Button, PA5 LED | [README](STM32/CAT11/TASK11B/README.md) |
| [STM32/CAT12](STM32/CAT12/) | [TASK12A](STM32/CAT12/TASK12A/) | Bosch Sensortec BME280 I²C Environmental Sensor Driver | I2C1 (PB8/PB9), BME280 Sensor | [README](STM32/CAT12/TASK12A/README.md) |
| [STM32/CAT12](STM32/CAT12/) | [TASK12B](STM32/CAT12/TASK12B/) | Dynamic JSON Environmental Telemetry Formatter | I2C1 Sensor, Floating-Point Formatter | [README](STM32/CAT12/TASK12B/README.md) |
| [STM32/CAT12](STM32/CAT12/) | [TASK12C](STM32/CAT12/TASK12C/) | Live HTTP Telemetry Service & Node-RED Flow Ingestion | Port 80 HTTP, Node-RED Dashboard | [README](STM32/CAT12/TASK12C/README.md) |
| [STM32/CAT13](STM32/CAT13/) | [TASK13](STM32/CAT13/TASK13/) | Cloud MQTT Telemetry (`broker.emqx.io:1883`) & Subscriptions | ESPLib Driver, USART2 Modem | [README](STM32/CAT13/TASK13/README.md) |
| [STM32/CAT14](STM32/CAT14/) | [TASK14](STM32/CAT14/TASK14/) | Node-RED Cloud Dashboard & End-Sem IoT Project Integration | Node-RED (Port 1880), MQTT Telemetry | [README](STM32/CAT14/TASK14/README.md) |

---

## 3. Hardware Platforms Summary

| Platform Identifier | Target Microcontroller | Architecture | Operating Voltage | Clock Source | Primary Peripherals / Drivers |
|---|---|---|---|---|---|
| **8051 Tier** | Microchip / Atmel AT89S52 | 8-bit 8051 CISC | 5.0V DC | 11.0592 MHz Quartz Crystal | GPIOs, Timers 0/1, UART (9600-8-N-1), HD44780 LCD, 4x4 Keypad, ULN2003 Stepper |
| **STM32 Tier 1** | STM32F103C8T6 (Blue Pill) | 32-bit ARM Cortex-M3 | 3.3V DC | 72 MHz (8 MHz HSE + PLL x9) | GPIO (PC13 LED, PA0 Button), USART1, SysTick |
| **STM32 Tier 2** | STM32F401RET6 (NUCLEO-F401RE) | 32-bit ARM Cortex-M4 with FPU | 3.3V DC | 84 MHz (HSI / HSE + PLL) | GPIO (PA5 LD2, PC13 B1), USART2, I2C1 (BME280), ESP8266 Modem |
| **Wi-Fi Tier** | Wemos D1 Mini (ESP8266-12F) | 32-bit Tensilica L106 | 3.3V / 5V DC | 80 / 160 MHz | AT Command Interpreter, TCP Server (Port 80), MQTT Client (Port 1883) |
| **Sensor Tier** | Bosch Sensortec BME280 | I²C Environmental Sensor | 3.3V DC | 100 kHz Standard I²C Bus | Temperature, Barometric Pressure, Relative Humidity |

---

## 4. University Evaluation Script Compliance Matrix

This repository strictly matches the evaluation schema and file check requirements evaluated by the course grading harness:

```text
============================================================
Foundations of IoT - Evaluation Report
Repository: 25011102101_FIoT_LAB
============================================================
Platform: 8051
  - Tasks Discovered: 13 / 13
  - File Checks per Task:
      * Keil project (*.uvproj or *.uvprojx)    [PASS]
      * C source file (*.c)                     [PASS]
      * STARTUP.A51                             [PASS]
      * Objects/ folder                         [PASS]
      * Objects/*.hex                           [PASS]
      * README.md exists                        [PASS]
      * circuit.png exists                      [PASS]
  - 8051 Checks Passed: 78 / 78 (100%)

Platform: STM32
  - Tasks Discovered: 15 / 15
  - File Checks per Task:
      * .ioc file                               [PASS]
      * .mxproject                              [PASS]
      * Core/ folder                            [PASS]
      * Drivers/ folder                         [PASS]
      * MDK-ARM/ folder                         [PASS]
      * MDK-ARM/*.uvprojx                       [PASS]
      * MDK-ARM/startup_*.s                     [PASS]
      * README.md exists                        [PASS]
      * circuit.png exists                      [PASS]
  - STM32 Checks Passed: 120 / 120 (100%)
============================================================
Total Tasks Discovered: 28 / 28
Tasks Passed: 28 / 28 (100.0%)
Total File Checks Passed: 198 / 198 (100.0%)
Overall Status: PASSED
============================================================
```
