#define SRV_BASE_PIN	2
#define SRV_PIN				2

#define MAX_MICROS		500											// Default values for fs5109m
#define MIN_MICROS		2500										// Default values for fs5109m

#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<driver/ledc.h>
#include<esp_wifi.h>

ledc_timer_config_t ledc_timer = {
	.speed_mode       = LEDC_LOW_SPEED_MODE,		// Maybe changes to LEDC_HIGH_SPEED_MODE
	.duty_resolution  = LEDC_TIMER_13_BIT,
	.timer_num        = LEDC_TIMER_0,
	.freq_hz          = 50,											// Default freq. for servo
	.clk_cfg          = LEDC_AUTO_CLK
};

ledc_channel_config_t ledc_channel = {
	.gpio_num       = SRV_PIN,
	.speed_mode     = LEDC_LOW_SPEED_MODE,			// Maybe changes to LEDC_HIGH_SPEED_MODE
	.channel        = LEDC_CHANNEL_0,
	.timer_sel      = LEDC_TIMER_0,
	.duty           = 0,
	.hpoint         = 0													// IDK
};

wifi_config_t wifi_config = {
	.sta = {
		.ssid = "huyna",// Change in the future
		.password = "passbitch", // Same
		.threshold.authmode = WIFI_AUTH_WPA2_PSK,
		.sae_pwe_h2e = WPA3_SAE_PWE_HUNT_AND_PECK,			// Maybe problems
		.sae_h2e_identifier = ""// Trash, if use simple router CONFIG_ESP_WIFI_PW_ID,
		// This really problem .disable_wpa3_compatible_mode = 0,				// Maybe problems
		//  error: 'wifi_sta_config_t' has no member named 'disable_wpa3_compatible_mode'
  },
};

void app_main() {
	// Wifi init, in the future move it.
	esp_netif_init();
	esp_event_loop_create_default();
	esp_netif_create_default_wifi_sta();
	esp_wifi_set_mode(WIFI_MODE_STA);
	esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
	esp_wifi_start();

	// LEDC init
	ledc_timer_config(&ledc_timer);
	ledc_channel_config(&ledc_channel);

	for (;;) {
		ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, 204); 
		ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

		vTaskDelay(pdMS_TO_TICKS(1000));

		ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, 1024); 
		ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
