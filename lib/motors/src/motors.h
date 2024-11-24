#pragma once

#define MOTOR_FORWARD 1
#define MOTOR_LEFT 2
#define MOTOR_RIGHT 3
#define MOTOR_BACKWARD 4
#define MOTOR_STOP 0

void motor_init();
void drive();
void update_motor_config(int current_button_state);
void drive_ramp();