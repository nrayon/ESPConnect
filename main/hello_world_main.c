/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_netif.h"

#define LOCAL_ESP_WIFI_SSID         CONFIG_ESP_WIFI_SSID
#define LOCAL_ESP_WIFI_PASS         CONFIG_ESP_WIFI_PASSWORD
#define WIFI_ESP_MAXIMUM_RETRY      CONFIG_ESP_MAXIMUM_RETRY

void app_main(void)
{


    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}

void init_wifi_station() {
    
}
