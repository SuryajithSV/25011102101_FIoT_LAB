# CAT 14 - TASK14A: Node-RED Flow Ingestion & Telemetry Processing

## 1. Experiment Name
**Node-RED Cloud Telemetry Flow Ingestion and Rule Engine**

## 2. Hardware Setup and Components
- 1x STM32 Nucleo-F401RE Development Board
- 1x ESP8266 Wi-Fi Module
- 1x Dedicated 3.3V Power Supply
- Node-RED Runtime (`localhost:1880`)

## 3. Circuit Diagram
![Circuit Diagram](circuit.png)

## 4. Required Pin Connections
| Nucleo Pin | Target Pin | Function |
|---|---|---|
| PA2 (USART2 TX) | ESP8266 RXD | AT command / telemetry transmit |
| PA3 (USART2 RX) | ESP8266 TXD | AT response / broker receive |
| PA5 | Onboard LD2 LED | Cloud actuation status |
| +3.3V / GND | ESP8266 Supply | Power (dedicated regulator) |

## 5. Clock Configuration
- System Clock: **84 MHz**
- USART2: 115200 baud, 8-N-1

## 6. Pseudocode / Code Logic
1. Initialize STM32 HAL, clocks, and USART2 interface.
2. Initialize ESP8266 Wi-Fi client and associate with local access point.
3. Route incoming MQTT sensor messages to Node-RED dashboard widgets.
4. Service keep-alive packets and state transitions in the main superloop.

## 7. Inference / Conclusion
- Successfully verified Node-RED flow telemetry parsing and edge event routing.
- Demonstrates reliable cloud telemetry communication and edge device control.
