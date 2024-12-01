#include <stdio.h>
#include <esp_wifi.h>
#include <esp_err.h>
#include <esp_log.h>
#include "esp_mesh.h"
#include <string.h>
#include "esp_mac.h"
#include "esp_event.h"
#include "esp_mesh_internal.h"
#include "nvs_flash.h"

void init_lwip_and_wifi();
void init_mesh();
void ip_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);
void mesh_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);

static const char *MESH_TAG = "wifi_mesh_sandbox";
static int mesh_layer = -1;

void app_main(void)
{

    init_lwip_and_wifi();
    init_mesh();
    configure_mesh();
    start_mesh();
}

// LwIP & WiFi
void init_lwip_and_wifi()
{
    ESP_ERROR_CHECK(esp_netif_init());

    /*  event initialization */
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    /*  Wi-Fi initialization */
    wifi_init_config_t config = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&config));
    /*  register IP events handler */
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &ip_event_handler, NULL));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_FLASH));
    ESP_ERROR_CHECK(esp_wifi_start());
}

void ip_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
    ip_event_got_ip_t *event;
    printf("ev_handle_called.\n");
    switch (event_id)
    {
    case IP_EVENT_STA_GOT_IP:
        event = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(MESH_TAG, "IP_EVENT_STA_GOT_IP");
        ESP_LOGI(MESH_TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
        break;
    default:
        ESP_LOGI(MESH_TAG, "event id:%" PRId32 "", event_id);
        break;
    }

    return;
}

void init_mesh()
{
    /*  mesh initialization */
    ESP_ERROR_CHECK(esp_mesh_init());
    /*  register mesh events handler */
    ESP_ERROR_CHECK(esp_event_handler_register(MESH_EVENT, ESP_EVENT_ANY_ID, &mesh_event_handler, NULL));
}

void mesh_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
    ESP_LOGI(MESH_TAG, "event id:%" PRId32 "", event_id);
}

static const uint8_t MESH_ID[6] = {0x77, 0x77, 0x77, 0x77, 0x77, 0x77};

void configure_mesh()
{
    /* Enable the Mesh IE encryption by default */
    mesh_cfg_t cfg = MESH_INIT_CONFIG_DEFAULT();
    /* mesh ID */
    memcpy((uint8_t *)&cfg.mesh_id, MESH_ID, 6);
    /* channel (must match the router's channel) */
    cfg.channel = CONFIG_MESH_CHANNEL;
    /* router */
    cfg.router.ssid_len = strlen(CONFIG_MESH_ROUTER_SSID);
    memcpy((uint8_t *)&cfg.router.ssid, CONFIG_MESH_ROUTER_SSID, cfg.router.ssid_len);
    memcpy((uint8_t *)&cfg.router.password, CONFIG_MESH_ROUTER_PASSWD,
           strlen(CONFIG_MESH_ROUTER_PASSWD));
    /* mesh softAP */
    cfg.mesh_ap.max_connection = CONFIG_MESH_AP_CONNECTIONS;
    memcpy((uint8_t *)&cfg.mesh_ap.password, CONFIG_MESH_AP_PASSWD,
           strlen(CONFIG_MESH_AP_PASSWD));
    ESP_ERROR_CHECK(esp_mesh_set_config(&cfg));
}

void start_mesh()
{
    /* mesh start */
    ESP_ERROR_CHECK(esp_mesh_start());
}