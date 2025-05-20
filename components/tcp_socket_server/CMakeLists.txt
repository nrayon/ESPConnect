idf_component_register(SRCS "tcp_socket_server.c"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_event
                    REQUIRES esp_netif
                    REQUIRES LED_switch_events)
