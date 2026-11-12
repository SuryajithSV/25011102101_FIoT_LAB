#include "main.h"
#include "ESPLib.h"
#include <stdio.h>

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

UART_HandleTypeDef huart2;

int main(void) {
    char json_data[64];
    float temperature = 28.5f;

    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();

    ESP8266_Init(StationMode, huart2);
    ESP8266_wifiConnect("LabWiFi", "LabPassword123");
    ESP8266_portConnect("TCP", "broker.emqx.io", "1883");

    MQTT_InitTypeDef_t mqttSetting = { 500, CleanSession, "STM32_Publisher" };
    MQTT_connectBroker(&mqttSetting);

    while (1) {
        sprintf(json_data, "{\"temp\":%.2f}", temperature);
        MQTT_publishTopic("stm32/test/data", json_data, QoS0);
        HAL_Delay(1000);
    }
}
