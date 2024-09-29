// MQTT Door Monitor
// Zack Sargent
// July 28th, 2024

#include <WiFi.h>
#include <PubSubClient.h>
#include "arduino-secrets.h"  // https://www.andreagrandi.it/posts/how-to-safely-store-arduino-secrets/

WiFiClient espClient;
PubSubClient client(espClient);

const char *topic = "norseiot/time_on";

String getClientId() {
  return "esp32-client-" + String(WiFi.macAddress());
}

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
    String client_id = getClientId();
    Serial.printf("The client %s is connecting to the public MQTT broker\n", client_id.c_str());
    if (client.connect(client_id.c_str())) {
      Serial.println("Public EMQX MQTT broker connected");
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void callback(char *topic, byte *payload, unsigned int length) {
  // we could handle messages here...
}

void loop() {
  client.loop();
  String client_id = getClientId();
  String message = client_id + " has been on for " + String(millis()) + " milliseconds!";
  client.publish(topic, message.c_str());
  Serial.print("Published: ");
  Serial.println(message);
  delay(1000);
}
