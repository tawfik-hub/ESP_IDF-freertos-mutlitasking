#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "esp_rom_gpio.h"
#include "freertos/timers.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "esp_pthread.h"

void read_debit(void *param);
void wifi_sending(void *param);

void app_main()
{
    xTaskCreate(read_debit, "reading", 1024*2, NULL, 3, NULL);
    xTaskCreate(wifi_sending, "sending", 1024*2, NULL, 3, NULL);

}

//reading function
void read_debit(void *param)
{
    while (1)
    {
        printf("this is reading function \n");
        vTaskDelay(300);
    }
    vTaskDelete(NULL);
}

//function wifi 
void wifi_sending(void *param)
{
    while(1)
    {
        printf("wifi function \n");
        vTaskDelay(400);

    }
    vTaskDelete(NULL);
}