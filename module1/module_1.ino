// Pause in milliseconds between screens, change to 0 to time font rendering
#define WAIT 500

#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

unsigned long targetTime = 0; // Used for testing draw times

void setup(void) {
  tft.init();
  tft.setRotation(1);
}

void loop() {
  targetTime = millis();

  // First we test them with a background colour set
  //https://stackoverflow.com/questions/7622887/generating-a-random-32-bit-hexadecimal-value-in-c
    int rand_color1 = rand() & 0xff;
    rand_color1 = rand() & 0xff;
    rand_color1 |= (rand() & 0xff) << 8;
    rand_color1 |= (rand() & 0xff) << 16;
    rand_color1 |= (rand() & 0xff) << 24;
    tft.setTextSize(3);
    tft.fillScreen(TFT_WHITE);
    tft.setTextColor(rand_color1);
    int xpos = rand() % (30 + 1 - 0) + 0;
    int ypos = rand() % (40 + 1 - 0) + 0;

    tft.drawString("Good", xpos, ypos, 2);
    
    delay(WAIT);
    int rand_color2 = rand() & 0xff;
    rand_color2 = rand() & 0xff;
    rand_color2 |= (rand() & 0xff) << 8;
    rand_color2 |= (rand() & 0xff) << 16;
    rand_color2 |= (rand() & 0xff) << 24;
    tft.setTextSize(3);
    tft.setTextColor(rand_color2);
    xpos = rand() % (120 + 1 - 0) + 0;
    ypos = rand() % (90 + 1 - 70) + 70;
    tft.drawString("Days", xpos, ypos, 2);
    delay(WAIT);
    
    tft.fillScreen(TFT_WHITE);
    tft.setTextSize(2);
    tft.setTextColor(rand_color1);
    tft.drawString("Good Days", 0, 0, 2);
    delay(WAIT);
    tft.setTextColor(rand_color2);
    tft.drawString("on", 30, 30, 2);
    delay(WAIT);
    tft.setTextColor(rand_color1);
    tft.drawString("my", 65, 65, 2);
    delay(WAIT);
    tft.setTextColor(rand_color2);
    tft.drawString("mind", 120, 100, 2);
    
  delay(900);;
}

