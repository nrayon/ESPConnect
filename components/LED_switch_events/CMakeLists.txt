idf_component_register(SRCS "LED_switch_events.c"
                    INCLUDE_DIRS "include"
                    REQUIRES "esp_event"
                    REQUIRES "esp_driver_gpio"
                    REQUIRES "espressif__led_strip")
