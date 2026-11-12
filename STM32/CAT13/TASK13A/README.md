# CAT 13 - Task 13A: BME280 Sensor Initialization

## 1. Experiment Name
**Bosch Sensortec BME280 I2C Environmental Sensor Device Bring-Up**

## 2. Hardware Setup and Components
- 1x STM32 Nucleo-F401RE Board
- 1x Bosch Sensortec BME280 Sensor Module
- 4x Female-to-Male Jumper Wires
- Mini-USB Cable & Keil MDK-ARM IDE

## 3. Circuit Diagram
![Circuit Diagram](circuit.png)

## 4. Required Pin Connections
| Nucleo Pin | BME280 Pin | Function |
|---|---|---|
| PB8 | SCL | I2C1 Serial Clock line |
| PB9 | SDA | I2C1 Serial Data line |
| +3.3V | VCC | 3.3V DC Sensor Power |
| GND | GND | Ground Reference |

## 5. Clock Configuration
- System Clock: **84 MHz**
- I2C1 Clock Speed: **100 kHz (Standard Mode)**

## 6. Pseudocode / Code Logic
1. Configure PB8 (SCL) and PB9 (SDA) in Open-Drain Alternate Function mode with external pull-ups.
2. Initialize I2C1 peripheral using `HAL_I2C_Init(&hi2c1)`.
3. Read BME280 Chip ID register (`0xD0`): expected value `0x60`.
4. Read factory trimming parameters (calibration coefficients) from registers `0x88` to `0xA1` and `0xE1` to `0xF0`.
5. Configure oversampling registers (`osrs_t`, `osrs_p`, `osrs_h`) and set Normal mode in `ctrl_meas`.

## 7. Inference / Conclusion
- Successfully verified communication with the BME280 sensor over I2C at address `0x76`.
- Read valid chip ID (`0x60`) and trimmed calibration data into memory.
