#include "wifiStation.h"
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"

//event group handle thing for RTOS
EventGroupHandle_t wifi_event_group;

void init_wifi_station() {
    //bind event handle?
    wifi_event_group = xEventGroupCreate();

    //init system functions for wifi
    esp_netif_create_default_wifi_sta();

    
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();



}

void event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data) {
    
}
