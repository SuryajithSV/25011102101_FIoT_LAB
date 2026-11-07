#include "main.h"

int main(void) {
    uint32_t press_time = 0;
    uint8_t pressed = 0;
    uint8_t fast_blink = 0;
    uint32_t last_blink = 0;

    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    while (1) {
        uint32_t now = HAL_GetTick();

        if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
            if (!pressed) {
                pressed = 1;
                press_time = now;
            }
        } else {
            if (pressed) {
                uint32_t elapsed = now - press_time;
                pressed = 0;

                if (elapsed >= 50) {
                    if (elapsed < 1000) {
                        fast_blink = 0;
                        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
                    } else {
                        fast_blink = !fast_blink;
                    }
                }
            }
        }

        if (fast_blink && (now - last_blink >= 80)) {
            last_blink = now;
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        }
    }
}
