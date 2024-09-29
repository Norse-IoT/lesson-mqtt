// MQTT Door Monitor
// Zack Sargent
// July 28th, 2024

#include <WiFi.h>
#include <PubSubClient.h>
#include "arduino-secrets.h" // https://www.andreagrandi.it/posts/how-to-safely-store-arduino-secrets/

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
    // Set software serial baud to 115200;
    Serial.begin(115200);
    // Connecting to a WiFi network
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the Wi-Fi network");
    //connecting to a mqtt broker
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(callback);
    while (!client.connected()) {
        String client_id = "esp32-client-";
        client_id += String(WiFi.macAddress());
        Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
        if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
            Serial.println("Public EMQX MQTT broker connected");
        } else {
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
        }
    }
    // Publish and subscribe
    // client.publish(topic, "Hi, I'm ESP32 ^^");
    client.subscribe(topic);
}

void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    for (int i = 0; i < length; i++) {
        Serial.print((char) payload[i]);
    }
    Serial.println();
    Serial.println("-----------------------");
}

void loop() {
    client.loop();
}


/* #include <SPI.h> */
/* #include <Wire.h> */
/* #include <Adafruit_GFX.h> */
/* #include <Adafruit_SSD1306.h> */


/* #define SCREEN_WIDTH 128  // OLED display width, in pixels */
/* #define SCREEN_HEIGHT 64  // OLED display height, in pixels */

/* // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins) */
/* #define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin) */
/* Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); */

/* uint16_t lastTimeDoorWasClosed; */

/* void setup() { */
  /* // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally */
  /* if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { */
    /* Serial.println(F("SSD1306 allocation failed")); */
    /* for (;;) */
      /* ;  // Don't proceed, loop forever */
  /* } */

  /* display.display(); */

  /* randomSeed(analogRead(0)); */
  /* lastTimeDoorWasClosed = millis(); */
  /* display.println("Welcome!"); */
  /* delay(1000); */
/* } */

/* void loop() { */
  /* bool door = isDoorOpen(); */
  /* displayDoorStatus(door); */
/* } */

/* bool isDoorOpen() { */
  /* return millis() % 1000 != 1;  // TODO: implement */
/* } */

/* void displayDoorStatus(bool doorIsOpen) { */
  /* display.clearDisplay(); */
  /* display.setTextSize(2); */
  /* display.setTextColor(WHITE); */
  /* display.setCursor(0, 0); */

  /* if (doorIsOpen) { */
    /* display.println("Open for"); */
    /* display.println(); */
    /* uint16_t timeOpenMs = millis() - lastTimeDoorWasClosed; */
    /* display.setTextSize(4); */
    /* display.print(timeOpenMs / 1000); */
  /* } else { */
    /* lastTimeDoorWasClosed = millis();  // door is currently closed */
    /* display.println("Closed"); */
  /* } */
  /* display.display(); */
/* } */

// String formatMs(uint16_t ms) {
//   uint16_t millisecondsPerSecond = 1 * 1000;
//   uint16_t millisecondsPerMinute = millisecondsPerSecond * 60;
//   uint16_t millisecondsPerHour = millisecondsPerMinute * 60;
//   uint16_t millisecondsPerDay = millisecondsPerHour * 24;

//   if (ms > millisecondsPerDay) {
//     return "TOO LONG!";
//   } else if (ms > millisecondsPerHour) {
//     return 
//   }
  

// }

