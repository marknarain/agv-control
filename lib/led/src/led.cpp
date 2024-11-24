#include <Arduino.h>
#include "led.h"

#define LED_PIN_RED 16
#define LED_PIN_GREEN 0
#define LED_PIN_BLUE 4

void led_init()
{
    pinMode(LED_PIN_RED, OUTPUT);
    digitalWrite(LED_PIN_RED, LOW);

    pinMode(LED_PIN_GREEN, OUTPUT);
    digitalWrite(LED_PIN_GREEN, LOW);
    
    pinMode(LED_PIN_BLUE, OUTPUT);
    digitalWrite(LED_PIN_BLUE, LOW);
}

// This function sets the RGB LED to the desired color
void led_set_rgb(bool red, bool green, bool blue)
{
    digitalWrite(LED_PIN_RED, red);
    digitalWrite(LED_PIN_GREEN, green);
    digitalWrite(LED_PIN_BLUE, blue);
}

void update_led_color(int state)
{
    switch (state)
    {
    case LED_STATE_RED:
        // Set the LED to red
        led_set_rgb(1, 0, 0);
        break;

    case LED_STATE_YELLOW:
        // Set the LED to yellow
        led_set_rgb(1, 1, 0);
        break;

    case LED_STATE_GREEN:
        // Set the LED to green
        led_set_rgb(0, 1, 0);
        break;

    case LED_STATE_CYAN:
        // Set the LED to cyan
        led_set_rgb(0, 1, 1);
        break;

    case LED_STATE_BLUE:
        // Set the LED to blue
        led_set_rgb(0, 0, 1);
        break;

    case LED_STATE_PINK:
        // Set the LED to purple
        led_set_rgb(1, 0, 1);
        break;

    case LED_OFF:
        // Set the LED to white
        led_set_rgb(0, 0, 0);
        break;
        
    default:
        // Turn off the LED
        led_set_rgb(0, 0, 0);
        break;
    }
}

