#ifndef LED_SWITCH_EVENT_HANDLER
#define LED_SWITCH_EVENT_HANDLER

#include "esp_event.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "led_strip.h"
#include "sdkconfig.h"

ESP_EVENT_DECLARE_BASE(LED_SWITCH_BASE);

#define LED_SWITCH_EVENT_ID 1

void configure_led();

void init_led_switch_event();
void post_led_switch_event();

#endif