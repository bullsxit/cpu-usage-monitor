#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String inputLine = "";

void setup() {
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true); // OLED init failed
  }
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 20);
  display.print("Waiting for");
  display.setCursor(0, 40);
  display.print("data...");
  display.display();
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      // Expected format: "LOAD:xx.x"
      if (inputLine.startsWith("LOAD:")) {
        String loadStr = inputLine.substring(5);
        float load = loadStr.toFloat();

        display.clearDisplay();
        display.setTextSize(3);
        display.setCursor(10, 15);
        display.print(load, 1);
        display.print("%");

        display.setTextSize(1);
        display.setCursor(10, 55);
        display.print("CPU Usage");

        display.display();
      }
      inputLine = "";
    } else {
      inputLine += c;
    }
  }
}
