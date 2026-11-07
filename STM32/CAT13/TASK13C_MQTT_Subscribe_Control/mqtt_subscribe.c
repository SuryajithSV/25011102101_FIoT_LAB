#include "main.h"
#include "ESPLib.h"
#include <string.h>

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

UART_HandleTypeDef huart2;
uint8_t uartRxData;
char mqttData[50];
char mqttTopic[10];

void SysTick_Handler(void) {
    MQTTTimer();
    HAL_IncTick();
}

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();

    ESP8266_Init(StationMode, huart2);
    ESP8266_wifiConnect("LabWiFi", "LabPassword123");
    ESP8266_portConnect("TCP", "broker.emqx.io", "1883");

    MQTT_InitTypeDef_t mqttSetting = { 500, CleanSession, "MqttSubscriber" };
    MQTT_connectBroker(&mqttSetting);
    MQTT_subscribeTopic("IOT", 0);

    HAL_UART_Receive_IT(&huart2, &uartRxData, 1);

    while (1) {
        MQTTDataHandler(mqttTopic, mqttData);
        if (strcmp(mqttData, "LED_ON") == 0 || strcmp(mqttData, "1") == 0) {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        } else if (strcmp(mqttData, "LED_OFF") == 0 || strcmp(mqttData, "0") == 0) {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        }
    }
}
