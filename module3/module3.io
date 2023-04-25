#include "Freenove_WS2812_Lib_for_ESP32.h"
#define LEDS_COUNT 15 // The number of led
#define LEDS_PIN 2 // define the pin connected to the Freenove 8 led strip
#define CHANNEL 0 // RMT channel
Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);
u8 m_color[5][3] = { {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {0, 0, 0} };
int delayval = 1000;
int xyzPins[] = {27, 26, 25};
float xPos = 0;
float yPos = 0;

void setup() {
strip.begin();
strip.setBrightness(10);

Serial.begin(115200);
pinMode(xyzPins[2], INPUT_PULLUP);  //z axis is a button.
pinMode(25, INPUT_PULLUP);  //button.
}


void loop() {
//TODO: Implement logic for pin values from joystick
for (int j = 0; j < 5; j++) {
for (int i = 0; i < LEDS_COUNT; i++) {
strip.setLedColorData(i, m_color[j][0], m_color[j][1], m_color[j][2]);
if (i > 0){
  strip.setLedColorData(i-1, 0, 0, 0);
}
strip.show();
delay(delayval);
}
delay(500);
}
}
