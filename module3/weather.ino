// Adapted code from
// https://randomnerdtutorials.com/esp32-http-get-open-weather-map-thingspeak-arduino/
#include <Arduino_JSON.h>
#include <HTTPClient.h>
#include <WiFi.h>

#include "Freenove_WS2812_Lib_for_ESP32.h"
#define LEDS_COUNT 15  // The number of led
#define LEDS_PIN 2 // define the pin connected to the Freenove 8 led strip #define CHANNEL 0
#define CHANNEL 0  // RMT channel
#include <iostream>
#include <string>

const char* ssid = "Barnard Secure";
const char* password = "mjs2408";

String openWeatherMapApiKey = "993fa629d0407ce4a7815309e9b3ec3c";

String city = "Manhattan";
String countryCode = "US";

// THE DEFAULT TIMER IS SET TO 1 HOUR
unsigned long lastTime = 0;
unsigned long timerDelay = 3600000;

Freenove_ESP32_WS2812 strip =
    Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);
u8 cloud_color[2][3] = {{128, 128, 128}, {220, 220, 220}};
u8 rain_color[2][3] = {{0, 0, 128}, {0, 0, 100}};
u8 sunny_color[2][3] = {{255, 255, 0}, {255, 255, 0}};
u8 hot_color[2][3] = {{255, 255, 0}, {0, 150, 0}};
int delayval = 100;

String jsonBuffer;

void setup() {
  strip.begin();
  strip.setBrightness(50);

  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println(
      "Timer set to 10 seconds (timerDelay variable), it will take 10 seconds "
      "before publishing the first reading.");
}

void loop() {
  // Send an HTTP GET request
  if ((millis() - lastTime) > timerDelay) {
    // Check WiFi connection status
    if (WiFi.status() == WL_CONNECTED) {
      String serverPath =
          "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," +
          countryCode + "&units=imperial" + "&APPID=" + openWeatherMapApiKey;

      jsonBuffer = httpGETRequest(serverPath.c_str());
      Serial.println(jsonBuffer);
      JSONVar myObject = JSON.parse(jsonBuffer);

      // JSON.typeof(jsonVar) can be used to get the type of the var
      if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
        return;
      }
      String temperature = "";
      String weather = "";

      Serial.print("JSON object = ");
      Serial.println(myObject);
      Serial.print("Temperature: ");
      Serial.println(myObject["main"]["temp"]);
      temperature = myObject["main"]["temp"];
      int temperature_int = stoi(temperature);
      weather = myObject["weather"]["main"];

      for (int j = 0; j < 2; j++) {
        for (int i = 0; i < LEDS_COUNT; i++) {
          if (weather == "Clouds") {
            strip.setLedColorData(i, cloud_color[j][0], cloud_color[j][1],
                                  cloud_color[j][2]);
            strip.show();
            delay(delayval);
          }

          if (weather == "Rain") {
            strip.setLedColorData(i, rain_color[j][0], rain_color[j][1],
                                  rain_color[j][2]);
            strip.show();
            delay(delayval);
          }

          if (temperature < 80) {
            strip.setLedColorData(i, sunny_color[j][0], sunny_color[j][1],
                                  sunny_color[j][2]);
            strip.show();
            delay(delayval);
          }

          if (temperature >= 80) {
            strip.setLedColorData(i, hot_color[j][0], hot_color[j][1],
                                  hot_color[j][2]);
            strip.show();
            delay(delayval);
          }
        }
        delay(500);
      }
      else {
        Serial.println("WiFi Disconnected");
      }
      lastTime = millis();
    }
  }

  String httpGETRequest(const char* serverName) {
    WiFiClient client;
    HTTPClient http;

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverName);

    // Send HTTP POST request
    int httpResponseCode = http.GET();

    String payload = "{}";

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      payload = http.getString();
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
    Serial.println(payload);
    return payload;
  }
