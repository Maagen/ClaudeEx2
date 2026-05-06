#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "uptime.h"

static const char *TAG1 = "TASK1";
static const char *TAG2 = "TASK2";
static const char *TAG3 = "TASK3";

static void task1(void *pvParameters)
{
    while (true) {
        ESP_LOGI(TAG1, "Hello from task1");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

static void task2(void *pvParameters)
{
    while (true) {
        ESP_LOGI(TAG2, "Hello from task2");
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}

static void task3(void *pvParameters)
{
    while (true) {
        uint64_t uptime_s = esp_timer_get_time() / 1000000ULL;
        ESP_LOGI(TAG3, "Uptime: %s", format_uptime(uptime_s).c_str());
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

extern "C" void app_main(void)
{
    xTaskCreate(task1, "task1", 2048, nullptr, 5, nullptr);
    xTaskCreate(task2, "task2", 2048, nullptr, 5, nullptr);
    xTaskCreate(task3, "task3", 2048, nullptr, 5, nullptr);
}
