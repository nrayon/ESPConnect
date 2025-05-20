#include <stdio.h>
#include "LED_switch_events.h"

#define LED_GPIO CONFIG_GPIO_NUMBER

static esp_event_loop_handle_t loop;

static const char* TAG = "LED_SWITCH_EVENT";

ESP_EVENT_DEFINE_BASE (LED_SWITCH_BASE);
static uint8_t LED_STATE = 0;


void configure_led(void)
{
    ESP_LOGI(TAG, "ESPConnect configured to GPIO LED.");
    gpio_reset_pin(LED_GPIO);
    
    //Sets the gpio direction to push/pull
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
}

/**
 * Turns on and off the LED based on the LED_STATE
 * We should probably use some type mutex here if we want multiple clients connecting.
 */
static void handleLEDSwitch(void* args, esp_event_base_t base, int32_t id, void* event_data)
{
    ESP_LOGI(TAG, "Received event with ID: %d", id);

    LED_STATE = !LED_STATE;
    gpio_set_level(LED_GPIO, LED_STATE);
   
}

/**
 * Initializes the LED switch event
 * This will link the event to a "loop" above and register the handle
 */
void init_led_switch_event()
{
    //Basic args
    esp_event_loop_args_t args = {
        .queue_size=5,
        .task_name="switch_led_task",
        .task_priority=1,
        .task_stack_size=2048,
        .task_core_id=tskNO_AFFINITY
    };
    //We create the looper with args
    esp_event_loop_create(&args, &loop);

    //Link the handleLEDSwitch function to the event
    esp_event_handler_instance_register_with(loop, LED_SWITCH_BASE, LED_SWITCH_EVENT_ID, handleLEDSwitch, NULL, NULL);
}

/**
 * This function posts an event to the queue.
 * Use this whenever you want to turn on or off the LED.
 */
void post_led_switch_event()
{
    esp_event_post_to(loop, LED_SWITCH_BASE, LED_SWITCH_EVENT_ID, NULL, 0, portMAX_DELAY);
}