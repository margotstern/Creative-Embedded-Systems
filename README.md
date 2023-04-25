# Creative-Embedded-Systems

# Module 2: Interactive Devices
Here, the goal was to create a interactive art installation that runs of a ESP32 TTGO T-Display. In the spirit of love and positivity in February, My inspiration for my creative embedded system was rooted in sustainability and environmentalism. My system allows the user to control the size and orbit of the sun, earth, and moon. See below the technical specifications to reproduce the work. 

See video: https://www.youtube.com/watch?v=b6ucSbkJO9Q '

See photo below :)
## BOM
- ESP32 TTGO T-display
- USB-C
- Mac (version 13.X)
- Solderless Breadboard
- a joystick
- 5 female to female wires

## Getting Started: Software
1. Download Arduino Legacy IDE (1.8.X): https://www.arduino.cc/en/software 
2. Download driver to get port /dev/cu.wchusbserialXXXXXXXX: https://www.wch.cn/downloads/CH34XSER_MAC_ZIP.html
3. Download Processing https://processing.org/download

## Getting Started: Hardware
1. Attach TTGO and joystick to the breadboard
2. Make the following wire connections: Joystick GND -> bottom right ground on the TTGO, Joystick 5V -> top right 3V, Joystick VRy -> TTGO 27, Joystick VRx -> TTGO 26, Joystick SW  -> TTGO 25
3. Plug in USB-C into computer and the ESP

## Dowload and Upload Code
1. To Download the code: `git clone https://github.com/margotstern/Creative-Embedded-Systems.git`
2. Open the file `module2.ino` in the Arduino IDE and select Upload
3. Opem the file `solarSystem.pde` in Processing IDE and select Run
4. Interact with the joystick and enjoy :)

![Getting Warmer Art Display](https://i.imgur.com/2sMuSdh.jpg)

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
