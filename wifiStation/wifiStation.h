#ifndef __WIFI_STATION_H__
#define __WIFI_STATION_H__

#define LOCAL_ESP_WIFI_SSID      CONFIG_ESP_WIFI_SSID
#define LOCAL_ESP_WIFI_PASS      CONFIG_ESP_WIFI_PASSWORD
#define LOCAL_ESP_MAXIMUM_RETRY  CONFIG_ESP_MAXIMUM_RETRY

//set of functions to handle connecting to wifi access point
void init_wifi_station();
#endif /*__WIFI_STATION_H__*/