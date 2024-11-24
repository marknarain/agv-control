#pragma once

#define LED_STATE_RED 1
#define LED_STATE_YELLOW 2
#define LED_STATE_GREEN 3
#define LED_STATE_CYAN 4
#define LED_STATE_BLUE 5
#define LED_STATE_PINK 6
#define LED_OFF 7

void led_init();
void update_led_color(int state);
