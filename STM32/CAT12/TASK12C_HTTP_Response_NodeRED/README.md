# CAT 12 - Task 12C: Node-RED Environmental Analytics

## 1. Experiment Name
**Node-RED Real-Time Environmental Dashboard & Statistical Analytics**

## 2. Hardware Setup and Software
- 1x STM32 Nucleo-F401RE Board with BME280 Sensor
- Node-RED runtime running on Host PC
- `node-red-dashboard` package installed

## 3. Circuit Diagram
![Circuit Diagram](circuit.png)

## 4. Required Connections
- Nucleo USB cable connected to PC (virtual serial port e.g. `COM3` / `/dev/ttyACM0`).

## 5. Clock Configuration
- Clock: **84 MHz**
- Telemetry ingestion baud rate: 115200 bps.

## 6. Flow Architecture & Logic
1. **Serial-In Node:** Ingests newline-delimited JSON strings from STM32.
2. **JSON Parser:** Converts JSON text to native JavaScript object.
3. **Analytics Function Node:**
   - Tracks running metrics: $T_{min}, T_{max}, T_{avg}$.
4. **Dashboard Nodes:**
   - Temperature & Humidity Gauges.
   - Historical trendline chart.

## 7. Inference / Conclusion
- Successfully ingested live embedded telemetry into Node-RED.
- Proves end-to-end IoT pipeline: physical silicon sensor $\rightarrow$ embedded JSON formatter $\rightarrow$ visual cloud analytics dashboard.
