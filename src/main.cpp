#include <Arduino.h>

#include "config.h"

#include <lcd_display.h>
#include <wifi_ap.h>
#include <web_server.h>
#include <led.h>
#include <motors.h>
#include <horn.h>
#include <rotary_switch.h>

int old_rotary_switch_position = 0;

void setup() 
{
	// Activate the serial communication
	Serial.begin(9600); //9600->Baudrate

	// Initialize the LCD display
	lcd_init();

	// Initialize the WiFi access point
	wifi_init(AGV_NAME, WIFI_PWD);

	// Initialize the pins of the RGB LED
	led_init();

	// Initialize the stepper motors
	motor_init();

	// Initialize the horn
	horn_init();

	// Initialize the rotary switch
	rotary_switch_init();

	// Start the web server
	start_webserver();

	// Print the AGV name and IP address on the LCD display
	lcd_print(0, 0, AGV_NAME);
	lcd_print(1, 0, ip_string());

	// Print the AGV name and IP address on the serial monitor
	Serial.print("AP IP address: ");
  	Serial.println(ip_string());
}

void loop() 
{
	int led_state = get_led_state_webserver();
	int button = get_button_webserver();
	int horn_state = get_horn_state_webserver();
	int rswitch_position = get_rotary_switch_position();

	if (rswitch_position != old_rotary_switch_position)
	{
		// make offset for the lcd one, if rswitch_position is > 9 and < 0 and 2 if rwswitch_position is < -9
		int lcd_offset = 0;
		if (rswitch_position > 9 || rswitch_position < 0)
		{
			lcd_offset++;
		}
		if (rswitch_position < -9)
		{
			lcd_offset++;
		}

		old_rotary_switch_position = rswitch_position;
		Serial.println(rswitch_position);
		lcd_print(1, 13, "   ");
		lcd_print(1, 15-lcd_offset, rswitch_position);
	}

	update_led_color(led_state);
	update_horn(horn_state, 500);
	update_motor_config(button);

	drive_ramp();
}