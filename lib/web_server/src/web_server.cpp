#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "web_server_index_html.h"
#include "led.h"
#include "motors.h"

AsyncWebServer server(80);

static int led_state = 0;
static int button_state = 0;
static int horn_state = 0;

void not_found(AsyncWebServerRequest *request) 
{
    request->send(404, "text/plain", "Not found");
}

void start_webserver()
{
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/html", index_html);
        request->send(200, "text/html", index_html);
    });

    // Commands from the webserver for the RGB LED
    server.on("/red", HTTP_GET, [] (AsyncWebServerRequest *request) {
        led_state = LED_STATE_RED;
        request->send(200, "text/plain", "ok");
    });

    server.on("/yellow", HTTP_GET, [] (AsyncWebServerRequest *request) {
        led_state = LED_STATE_YELLOW;
        request->send(200, "text/plain", "ok");
    });
 
    server.on("/green", HTTP_GET, [] (AsyncWebServerRequest *request) {
        led_state = LED_STATE_GREEN;
        request->send(200, "text/plain", "ok");
    });

    server.on("/cyan", HTTP_GET, [] (AsyncWebServerRequest *request) {
        led_state = LED_STATE_CYAN;
        request->send(200, "text/plain", "ok");
    });

    server.on("/blue", HTTP_GET, [] (AsyncWebServerRequest *request) {
        led_state = LED_STATE_BLUE;
        request->send(200, "text/plain", "ok");
    });

    server.on("/pink", HTTP_GET, [] (AsyncWebServerRequest *request) {
        led_state = LED_STATE_PINK;
        request->send(200, "text/plain", "ok");
    });
  
    server.on("/ledoff", HTTP_GET, [] (AsyncWebServerRequest *request) {
        led_state = LED_OFF;
        request->send(200, "text/plain", "ok");
    });


    // Button "front" pressed
    server.on("/forward", HTTP_GET, [] (AsyncWebServerRequest *request) {
        button_state = MOTOR_FORWARD;
        request->send(200, "text/plain", "ok");
    });

    // Button "left" pressed
    server.on("/left", HTTP_GET, [] (AsyncWebServerRequest *request) {
        button_state = MOTOR_LEFT;
        request->send(200, "text/plain", "ok");
    });

    // Button "right" pressed
    server.on("/right", HTTP_GET, [] (AsyncWebServerRequest *request) {
        button_state = MOTOR_RIGHT;
        request->send(200, "text/plain", "ok");
    });
 
    // Button "back" pressed
    server.on("/back", HTTP_GET, [] (AsyncWebServerRequest *request) {
        button_state = MOTOR_BACKWARD;
        request->send(200, "text/plain", "ok");
    });

    server.on("/off", HTTP_GET, [] (AsyncWebServerRequest *request) {
        button_state = MOTOR_STOP;
        horn_state = 0;
        request->send(200, "text/plain", "ok");
    });

    server.on("/HONK", HTTP_GET, [] (AsyncWebServerRequest *request) {
        horn_state = 1;
        request->send(200, "text/plain", "ok");
    });

    server.onNotFound(not_found);
    server.begin();
}

int get_led_state_webserver()
{
    return led_state;
}

int get_button_webserver()
{
    return button_state;
}

int get_horn_state_webserver()
{
    return horn_state;
}