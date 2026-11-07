#include "main.h"
#include <string.h>
#include <stdio.h>

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

static const char html_body[] = 
    "<html><body><h1>STM32 IoT Node</h1><p>Hello from STM32</p></body></html>";

void handle_http_request(int link_id) {
    char http_response[300];
    char cipsend_cmd[32];
    char close_cmd[32];

    int body_length = strlen(html_body);

    /* Construct RFC-compliant HTTP response */
    sprintf(http_response,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: %d\r\n"
            "\r\n"
            "%s", body_length, html_body);

    int total_length = strlen(http_response);

    /* Step 1: Send CIPSEND */
    sprintf(cipsend_cmd, "AT+CIPSEND=%d,%d\r\n", link_id, total_length);
    HAL_UART_Transmit(&huart2, (uint8_t*)cipsend_cmd, strlen(cipsend_cmd), HAL_MAX_DELAY);
    HAL_Delay(200);

    /* Step 2: Send HTTP Response */
    HAL_UART_Transmit(&huart2, (uint8_t*)http_response, total_length, HAL_MAX_DELAY);
    HAL_Delay(200);

    /* Step 3: Close TCP Connection */
    sprintf(close_cmd, "AT+CIPCLOSE=%d\r\n", link_id);
    HAL_UART_Transmit(&huart2, (uint8_t*)close_cmd, strlen(close_cmd), HAL_MAX_DELAY);
}

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART1_UART_Init();
    MX_USART2_UART_Init();

    /* Server initialization loop */
    while (1) {
        /* Monitor for +IPD and call handle_http_request(link_id) */
    }
}
