#define SRV_BASE_PIN	2
#define SRV_PIN				2

#define MAX_MICROS		500											// Default values for fs5109m
#define MIN_MICROS		2500										// Default values for fs5109m

#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<driver/ledc.h>

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

void app_main() {
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
