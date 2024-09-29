#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

uint16_t lastTimeDoorWasClosed;

void setup() {
// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
Serial.println(F("SSD1306 allocation failed"));
for (;;)
;  // Don't proceed, loop forever
}

display.display();

randomSeed(analogRead(0));
lastTimeDoorWasClosed = millis();
display.println("Welcome!");
delay(1000);
}

void loop() {
bool door = isDoorOpen();
displayDoorStatus(door);
}

bool isDoorOpen() {
return millis() % 1000 != 1;  // TODO: implement
}

void displayDoorStatus(bool doorIsOpen) {
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(0, 0);

if (doorIsOpen) {
display.println("Open for");
display.println();
uint16_t timeOpenMs = millis() - lastTimeDoorWasClosed;
display.setTextSize(4);
display.print(timeOpenMs / 1000);
} else {
lastTimeDoorWasClosed = millis();  // door is currently closed
display.println("Closed");
}
display.display();
}

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

