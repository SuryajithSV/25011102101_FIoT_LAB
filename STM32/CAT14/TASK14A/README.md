# CAT 14 - Task 14A: Local MQTT Broker Telemetry with ESPLib

## 1. Experiment Name
**STM32 + ESP8266 MQTT Telemetry Publisher using ESPLib**

## 2. Hardware Setup and Components
- 1x STM32 Nucleo-F401RE Board
- 1x ESP8266 Wi-Fi Module (Wemos D1 / ESP-01)
- 1x Dedicated 3.3V Power Supply
- Host PC running local Mosquitto MQTT Broker

## 3. Circuit Diagram
![Circuit Diagram](circuit.png)

## 4. Required Pin Connections
| Nucleo Pin | Target Pin | Function |
|---|---|---|
| PA2 (USART2 TX) | ESP8266 RXD | Send MQTT commands |
| PA3 (USART2 RX) | ESP8266 TXD | Receive MQTT responses |
| +3.3V / GND | Power Source | Regulated 3.3V DC |

## 5. Clock Configuration
- System Clock: **84 MHz**
- USART2: 115200 bps, 8-N-1

## 6. Pseudocode / Code Logic
1. Initialize ESPLib: `ESP8266_Init(StationMode, huart2)`.
2. Connect to Wi-Fi access point: `ESP8266_wifiConnect("SSID", "PASS")`.
3. Open TCP socket to MQTT Broker: `ESP8266_portConnect("TCP", "192.168.1.100", "1883")`.
4. Transmit MQTT CONNECT packet with Client ID.
5. In periodic timer: publish sensor telemetry payload to topic `stm32/bme280/data`.

## 7. Inference / Conclusion
- Validated lightweight MQTT packet generation and transmission using ESPLib driver.
