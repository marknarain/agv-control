# AGV Control Library for ESP32

Version 1.1 - 25.11.2024

This repository contains a functions for controlling various components of the **Autonomous Guided Vehicle (AGV)**. The library is designed for the ESP32 microcontroller and provides modular functionality for interaction with the AGV's hardware.

## Features

The library includes modules for the following components:
- **Motors**
- **LED**
- **Horn**
- **LCD Display**
- **WiFi Access Point (AP)**
- **Webserver**
- **Rotary Switch**

## Requirements

- **Microcontroller**: ESP32
- **Development Environment**: [PlatformIO](https://platformio.org/)
- **Dependencies**:
  - [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) (for the webserver)
  - [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C) (for the LCD display)

## Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/marknarain/agv-control.git