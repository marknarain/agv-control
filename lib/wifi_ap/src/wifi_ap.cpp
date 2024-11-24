#include <WiFi.h>

// Make a static variable to store the IP address
// Static, because we only want to use it in this file
static IPAddress agv_IP;

void wifi_init(const char* wifi_name, const char* wifi_pwd)
{
    // Start a WiFi access point using the WiFi library
    WiFi.softAP(wifi_name, wifi_pwd);
    agv_IP = WiFi.softAPIP();
}

char* ip_string()
{
    // Allocate memory for the IP address string
    // The IP address is 4 bytes long, and each byte is 3 characters long = 12
    // 16, because we need to add the dots and the null terminator
    char* ip_str = (char*)malloc(16);

    if (ip_str != NULL)
    {
        // We format the IP address into a string
        snprintf(ip_str, 16, "%d.%d.%d.%d", agv_IP[0], agv_IP[1], agv_IP[2], agv_IP[3]);
    }
    return ip_str;
}