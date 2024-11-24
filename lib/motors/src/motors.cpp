#include <Arduino.h>
#include "motors.h"

// PIN numbers for the stepper motor
#define EN_L 25
#define DIR_L 26
#define STP_L 27
#define EN_R 14
#define DIR_R 12
#define STP_R 13

#define FORWARD_PAUSE_TIME_MS 3500
#define BACKWARD_PAUSE_TIME_MS 3500
#define LEFT_PAUSE_TIME_MS 4500
#define RIGHT_PAUSE_TIME_MS 4500

#define DEFAULT_PAUSE_TIME_MS 4000
#define MIN_PAUSE_TIME_MS 1000

#define ACCELERATION_MS2 2

static unsigned long old_time = 0;
static int motor_pause_time;
static int old_button_state;

void motor_init() 
{
    motor_pause_time = DEFAULT_PAUSE_TIME_MS;
    old_button_state = 0;

    old_time = micros();

    // Set the motor pins as outputs
    pinMode(EN_L, OUTPUT);
    pinMode(DIR_L, OUTPUT);
    pinMode(STP_L, OUTPUT);

    pinMode(EN_R, OUTPUT);
    pinMode(DIR_R, OUTPUT);
    pinMode(STP_R, OUTPUT);
}

void update_motor_config(int current_button_state)
{
    // If the switch is not in the STOP position, enable the motors
    if(current_button_state != 0) 
    {
        digitalWrite(EN_L,LOW);
        digitalWrite(EN_R,LOW);
    }
    // If the switch is in the STOP position, disable the motors
    else 
    {
        digitalWrite(EN_L,HIGH);
        digitalWrite(EN_R,HIGH);
    }

    if (current_button_state != old_button_state)
    {
        // We need to set the motor states based on the switch state
        switch(current_button_state)
        {  
        case MOTOR_FORWARD: // forward
            digitalWrite(DIR_R, LOW);      // Motor right forward
            digitalWrite(DIR_L,HIGH);     // Motor left forward (other direction, because mounted mirrored) 
            motor_pause_time = FORWARD_PAUSE_TIME_MS;
            break;
        case MOTOR_LEFT: // left 
            digitalWrite(DIR_R, LOW);
            digitalWrite(DIR_L,LOW);
            motor_pause_time = LEFT_PAUSE_TIME_MS;
            break;
        case MOTOR_RIGHT:  // right
            digitalWrite(DIR_R, HIGH);
            digitalWrite(DIR_L,HIGH);
            motor_pause_time = RIGHT_PAUSE_TIME_MS;
            break;
        case MOTOR_BACKWARD:  // back
            digitalWrite(DIR_R, HIGH);
            digitalWrite(DIR_L,LOW);
            motor_pause_time = BACKWARD_PAUSE_TIME_MS;
            break;
        }

        old_button_state = current_button_state;
    }
}

// Lets the stepper motors drive one step. 
// This happens based on the config of the motor direction.
void drive()
{
    // Move the left motor
    digitalWrite(STP_L,!digitalRead(STP_L)); 
    // Move the right motor   
    digitalWrite(STP_R,!digitalRead(STP_R));
    // Pause to let the motor move
    delayMicroseconds(motor_pause_time); 
}

// Lets the stepper motors drive one step and then reduces the pause time.
// This lets the motors accelerate.
void drive_ramp()
{
    drive();

    unsigned long current_time = micros();
 
    // As long as the pause time is greater than the minimum pause time, reduce the pause time
    // If we go below the minimum pause time (1000) the motors don't move anymore
    if (motor_pause_time >= MIN_PAUSE_TIME_MS)
    {
        if (current_time - old_time > 1000)
        {
            motor_pause_time -= ACCELERATION_MS2;
            old_time = current_time;
        }
    }
}