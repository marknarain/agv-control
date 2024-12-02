#pragma once

#define MOTOR_FORWARD 1
#define MOTOR_LEFT 2
#define MOTOR_RIGHT 3
#define MOTOR_BACKWARD 4
#define MOTOR_STOP 0

#define FORWARD_PAUSE_TIME_US 3500
#define BACKWARD_PAUSE_TIME_US 3500
#define LEFT_PAUSE_TIME_US 4500
#define RIGHT_PAUSE_TIME_US 4500

#define USE_DEFAULT_PAUSE_TIMES -1

void motor_init();
void drive(int forward_pause_time = FORWARD_PAUSE_TIME_US,
           int left_pause_time = LEFT_PAUSE_TIME_US, 
           int right_pause_time = RIGHT_PAUSE_TIME_US, 
           int backward_pause_time = BACKWARD_PAUSE_TIME_US);
void update_motor_config(int current_button_state);
void drive_ramp();
void drive_speed_percent(int forward_percent = 50, 
                         int left_percent = 50, 
                         int right_percent = 30, 
                         int backward_percent = 30);