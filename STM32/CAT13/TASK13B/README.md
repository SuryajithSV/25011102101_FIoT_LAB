# CAT 13 - Task 13B: Periodic Sensor Telemetry Publishing

## 1. Experiment Name
**MQTT Sensor Data Publishing to Cloud Broker**

## 2. Hardware Setup and Components
- 1x STM32 Nucleo-F401RE Board
- 1x ESP8266 Wi-Fi Module
- 1x Dedicated 3.3V Power Supply
- Public MQTT Broker: `broker.emqx.io` (Port 1883)

## 3. Circuit Diagram
![Circuit Diagram](circuit.png)

## 4. Required Pin Connections
| Nucleo Pin | Target Pin | Function |
|---|---|---|
| PA2 (USART2 TX) | ESP8266 RXD | Send MQTT publish packets |
| PA3 (USART2 RX) | ESP8266 TXD | Receive responses |
| PA5 | Onboard LD2 LED | Pulse on publish event |
| 3.3V / GND | Power Source | Power rails |

## 5. Clock Configuration
- System Clock: **84 MHz**
- Publish Interval: **5000 ms (5 seconds)**

## 6. Pseudocode / Code Logic
1. Establish Wi-Fi and MQTT connection as configured in Task 13A.
2. In the `while (1)` main loop:
   - Read or simulate sensor values (`temperature`, `humidity`).
   - Format data into a JSON string payload:
     ```c
     sprintf(payload, "{\"temp\":%.1f,\"humidity\":%.1f}", temp, hum);
     ```
   - Publish to topic `stm32/sensor/data` with QoS 0:
     ```c
     MQTT_publishTopic("stm32/sensor/data", payload, QoS0);
     ```
   - Briefly toggle LD2 LED on PA5 to visually confirm transmission.
   - Wait 5 seconds using `HAL_Delay(5000)`.

## 7. Inference / Conclusion
- Live telemetry was published periodically to the cloud broker without dropped packets.
- Subscribed clients (MQTTX desktop client and web console) received the real-time JSON payloads.
