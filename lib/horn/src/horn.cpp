#include <Arduino.h>

#define HORN_PIN 17

#define HONK_DURATION 500

// start_time stores, when the honking started, so we can stop it after a certain time
static unsigned long start_time; 

// is_honking is a flag to check if we are currently honking
static bool is_honking;      

// old_horn_state stores the previous state of the horn
// This allows us to make sure the horn only honks once, when the button is pressed
static int old_horn_state;

void horn_init()
{
    // The start time is 0, because we haven't started honking yet
    start_time = 0;
    is_honking = false;
    old_horn_state = 0;
    pinMode(HORN_PIN, OUTPUT);
}

void horn_on()
{
    digitalWrite(HORN_PIN, HIGH);
}

void horn_off()
{
    digitalWrite(HORN_PIN, LOW);
}

void update_horn(int horn_state, int honk_time)
{
    // current_time stores the current time in milliseconds and is used to calculate the time the horn has been honking
    unsigned long current_time = millis();      

    // If the horn state has changed, we check if the horn should honk
    if (horn_state != old_horn_state) 
    {
        // If the horn is pressed and we are not currently honking, we start honking
        if (horn_state == 1 && !is_honking) 
        {
            start_time = current_time; 
            is_honking = true;         
        }
        old_horn_state = horn_state;
    }

    // If the horn is honking and the time has not yet passed, we keep honking
    if (is_honking && (current_time - start_time < honk_time))
    {
        horn_on(); 
    }
    else
    {
        // If the time has passed, we stop honking
        horn_off();     
        is_honking = false; 
    }
    
}

