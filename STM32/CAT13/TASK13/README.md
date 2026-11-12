# CAT 13 - Cloud MQTT Telemetry & Remote Control

## 1. Experiment Name
**STM32F401 & ESP8266 Cloud IoT Integration Using MQTT Protocol**

## 2. Hardware Setup and Components
- 1x STM32 Nucleo-F401RE Board (ARM Cortex-M4 @ 84 MHz)
- 1x ESP8266 Wi-Fi Module (Wemos D1 Mini / ESP-01)
- 1x Dedicated 3.3V Power Supply
- Onboard Nucleo LD2 User LED on PA5
- Public MQTT Broker: `broker.emqx.io` (Port 1883)

## 3. Circuit Diagram
![Circuit Diagram](circuit.png)

## 4. Required Pin Connections
| Nucleo Pin | Connected To | Function |
|---|---|---|
| PA2 (USART2 TX) | ESP8266 RXD | Send AT & MQTT packets |
| PA3 (USART2 RX) | ESP8266 TXD | Receive incoming MQTT packets |
| PA5 | Onboard LD2 LED | Actuator output |
| 3.3V / GND | Power Rails | Power supply |

## 5. Clock Configuration
- System Clock: **84 MHz (HSI + PLL)**
- USART2 Baud Rate: **115200 bps**
- SysTick Timer: Used by `MQTTTimer()` to track keep-alive pings.

## 6. Subtask Organization
- **TASK13A:** MQTT Broker Connection & Handshake (`broker.emqx.io:1883`)
- **TASK13B:** Periodic Telemetry Publishing (`iot/sensor/data`)
- **TASK13C:** Cloud Subscription & Remote LED Actuation (`iot/actuator/led`)
- **TASK13D:** Node-RED Real-Time Cloud Dashboard & Toggle Switch

## 7. Inference / Conclusion
- Built an end-to-end cloud IoT system on STM32 using the ESPLib library.
- Verified bidirectional telemetry: publishing sensor data to the cloud broker and receiving remote control commands back to the hardware.
