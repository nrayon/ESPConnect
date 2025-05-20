idf_component_register(SRCS "main.c"
                    PRIV_REQUIRES spi_flash
                    REQUIRES esp_wifi
                    REQUIRES wifiStation
                    REQUIRES nvs_flash
                    REQUIRES tcp_socket_server
                    REQUIRES LED_switch_events)
