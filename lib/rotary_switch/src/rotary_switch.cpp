#include <Arduino.h>

#define DEBOUNCE_MUS 50000

// Rotary switch pins
#define RE1 19
#define RE2 18

static unsigned long current_position;
static int old_state_RE1;
static int old_state_RE2;

void rotary_switch_init() 
{
    // Start to count at the middle of the value range (ca. 2 billion), so we can count down or up
    // as long as we want without running into an overflow.
    // Start with a value, which is a multiple of 24
    current_position = 0x7FFFFFE1;

    pinMode(RE1, INPUT);
    pinMode(RE2, INPUT);

    old_state_RE1 = digitalRead(RE1);
    old_state_RE2 = digitalRead(RE2);
}

int get_rotary_switch_position() 
{
    int current_state_RE1 = digitalRead(RE1);
    int current_state_RE2 = digitalRead(RE2);

    int step = 0;

    // Detect state change on RE1
    if (current_state_RE1 != old_state_RE1) 
    {
        // Determine rotation direction based on RE2 state
        if (current_state_RE2 == LOW) 
        {
            step = 1;
        } 
        else 
        {
            step = -1;
        }

        if (current_state_RE1 == LOW) 
        {
            step = -step;
        }
        
        current_position = (current_position + step);
    }

    // Update last states
    old_state_RE1 = current_state_RE1;
    old_state_RE2 = current_state_RE2;

    return (current_position / 2) % 24;
}