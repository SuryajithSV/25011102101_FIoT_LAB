# STM32F401RE Cortex-M4 – Task 3: Short vs Long Press Detection

## 1. Experiment Details
- **Experiment Identifier:** CONTINUOUS LAB EVALUATION-11 (Week 11)
- **Experiment Name:** STM32F401RE Cortex-M4: GPIO and User Input Programming
- **Hardware Platform:** NUCLEO-F401RE Development Board
- **Task Number:** TASK 3 — Short-Press and Long-Press Detection Engine

---

## 2. Hardware Setup and Components
| Component | Description |
|---|---|
| NUCLEO-F401RE | 84 MHz ARM Cortex-M4 |
| B1 User Switch | PC13 (Active LOW) |
| LD2 User LED | PA5 (Active HIGH) |

---

## 3. Circuit Diagram
![Circuit Diagram](circuit.png)

---

## 4. Required Pin Connections
| Nucleo Signal | Pin | Peripheral | Function |
|---|---|---|---|
| B1 Push-Button | PC13 | Digital Input | Active LOW input |
| LD2 LED | PA5 | Digital Output | Active HIGH visual actuator |

---

## 5. Clock Configuration & Timing Specifications
- **Core Clock:** 84 MHz
- **Short Press ($\Delta t < 1000\text{ ms}$):** Toggles LD2 state once.
- **Long Press ($\Delta t \ge 1000\text{ ms}$):** Toggles rapid 10 Hz heartbeat strobe mode.

---

## 6. Pseudocode / Code Logic
```c
uint32_t t_down = 0;
uint8_t btn_pressed = 0;
uint8_t strobe_mode = 0;
uint32_t last_strobe = 0;

while (1) {
    uint32_t now = HAL_GetTick();

    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
        if (!btn_pressed) {
            btn_pressed = 1;
            t_down = now;
        }
    } else {
        if (btn_pressed) {
            uint32_t duration = now - t_down;
            btn_pressed = 0;
            if (duration >= 50) {
                if (duration < 1000) {
                    /* Short Press: Discrete Toggle */
                    strobe_mode = 0;
                    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
                } else {
                    /* Long Press: Rapid Strobe */
                    strobe_mode = !strobe_mode;
                }
            }
        }
    }

    if (strobe_mode && (now - last_strobe >= 50)) {
        last_strobe = now;
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    }
}
```

---

## 7. Inference / Conclusion
- Accurately differentiated between transient taps and deliberate long presses on the NUCLEO-F401RE.
- Demonstrated robust non-blocking temporal input processing on an ARM Cortex-M4 processor.
