# Norse IoT Club: MQTT Lesson

For this project, you will need:
- An ESP32, or equivalent
- An MQTT network

This project uses an "arduino-secrets.h" file in the root directory.

**This should be in a file called `arduino-secrets.h`.** 
Make sure it is in the same folder as `README.md`. Do not put it in any of the `lesson-*` folders.

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
