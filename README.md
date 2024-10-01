# Norse IoT Club: MQTT Lesson

## HOW TO USE THIS CODE:

If you want to work with this code, you can **either**:

1. [download the zip file](https://github.com/Norse-IoT/lesson-mqtt/archive/refs/heads/main.zip)
2. run the command `git clone https://github.com/Norse-IoT/lesson-mqtt.git` 
3. clone this via [GitHub desktop](https://desktop.github.com/download/)

Then, you can use [Arduino IDE](https://www.arduino.cc/en/software) to open each `.ino` file.

## Setup Required

For this project, you will need:
- An ESP32, or equivalent
- An MQTT network

Every lesson folder has a file called `arduino-secrets.h` which you'll need to update with the Wi-Fi password.

```cpp
#pragma once

// WiFi
const char *ssid = "NORSEIOT5G";
const char *password = "YOUR_PASSWORD";  // Enter Wi-Fi password

// MQTT Broker
const char *mqtt_broker = "10.0.1.2";
const int mqtt_port = 1883;
```

------

Relevant links:

- <https://mqtt-explorer.com/> - Recommended Desktop MQTT explorer
- <https://norseiot.club/>
- <https://wiki.norseiot.club/>
