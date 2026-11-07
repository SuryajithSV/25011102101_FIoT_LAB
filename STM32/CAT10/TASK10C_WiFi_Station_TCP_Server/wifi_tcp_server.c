#include "main.h"
#include <string.h>

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

void send_at(const char *cmd, uint32_t delay_ms) {
    HAL_UART_Transmit(&huart2, (uint8_t*)cmd, strlen(cmd), HAL_MAX_DELAY);
    HAL_Delay(delay_ms);
}

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART1_UART_Init();
    MX_USART2_UART_Init();

    /* Bring up Wi-Fi TCP Server on Port 80 */
    send_at("AT\r\n", 500);
    send_at("AT+CWMODE=1\r\n", 500);
    send_at("AT+CWJAP=\"LabWiFi\",\"Password123\"\r\n", 5000);
    send_at("AT+CIFSR\r\n", 1000);
    send_at("AT+CIPMUX=1\r\n", 500);
    send_at("AT+CIPSERVER=1,80\r\n", 500);

    while (1);
}
