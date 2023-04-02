# Creative-Embedded-Systems

#Module 2: Interactive Devices

# Module 1: Generative Art
Here, the goal was to create a generative art installation that runs of a ESP32 TTGO T-Display. In the spirit of love and positivity in February, I decided to create generative art from SZA’s acclaimed song, Good Days. See below the technical specifications to reproduce the work. 




See Video: https://youtube.com/shorts/8n0QKmH3J9U?feature=share

See Photo Below :)
## BOM
- ESP32 TTGO T-display
- USB-C
- Mac (version 13.X)

## Getting Started
1. Download Arduino Legacy IDE (1.8.X): https://www.arduino.cc/en/software 
2. Download driver to get port /dev/cu.wchusbserialXXXXXXXX: https://www.wch.cn/downloads/CH34XSER_MAC_ZIP.html

## Setting Up IDE
1. Navigate to Preferences: Ardunio --> Settings 
2. To enable the board, in Additional Boards Manager, copy and paste URL: https://dl.espressif.com/dl/package_esp32_index.json
3. Navigate to Tools --> Board, Select ESP32 Arduino --> TTGO T1
4. Return to Tools, select Port --> /dev/cu.wchusbserialXXXXXXXX
5. In Tools, also select Manage library, install tft_eSPI by Bodner
6. In your computer's finder, go to file User_Setup_Select.h, comment out all the lines except for line: `#include<User_Setups/Setup25_TTGO_T_Display.h>`

## Dowload and Upload Code
1. To Download the code: `git clone https://github.com/margotstern/Creative-Embedded-Systems.git`
2. Open the file `module_1.ino` in the Arduino IDE
3. Plug in USB-C into computer and the ESP
4. Select Upload and enjoy :)


![Good Days](https://i.imgur.com/RUWO6kW.jpg)
