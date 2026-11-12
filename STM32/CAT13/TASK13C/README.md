# CAT 13 - Task 13C: Live Telemetry Web Service

## 1. Experiment Name
**Real-Time BME280 Environmental Telemetry Server & Node-RED Dashboard**

## 2. Hardware Setup and Components
- 1x STM32 Nucleo-F401RE Board
- 1x Bosch Sensortec BME280 Sensor Module
- 1x ESP8266 Wi-Fi Module (Wemos D1 / ESP-01)
- Host PC running Node-RED

## 3. Circuit Diagram
![Circuit Diagram](circuit.png)

## 4. Required Pin Connections
| Nucleo Pin | Target Component | Function |
|---|---|---|
| PB8 / PB9 | BME280 SCL / SDA | I2C1 Sensor Bus |
| PA2 / PA3 | ESP8266 RXD / TXD | USART2 Wi-Fi AT Interface |
| +3.3V / GND | Regulated Power Rails | Power Supply |

## 5. Clock Configuration
- System Clock: **84 MHz**
- I2C1: 100 kHz
- USART2: 115200 bps

## 6. Pseudocode / Code Logic
1. Initialize BME280 sensor and connect ESP8266 to local Wi-Fi.
2. Start TCP server on port 80 (`AT+CIPSERVER=1,80`).
3. On incoming HTTP GET request:
   - Read latest sensor data.
   - Construct HTTP header: `HTTP/1.1 200 OK\r\nContent-Type: application/json\r\n...`.
   - Send JSON payload via `AT+CIPSEND`.
4. In Node-RED: configure `http request` polling node and dashboard gauge widgets.

## 7. Inference / Conclusion
- Sensor data successfully streamed over local Wi-Fi to interactive Node-RED gauges.
