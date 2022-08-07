#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <M5Unified.h>

const char *ssid = "xxxxxx";
const char *password = "xxxxxx";

String payload;

void setup()
{
  Serial.begin(119200);
  WiFi.begin(ssid, password);

  auto cfg = M5.config();
  M5.begin(cfg);

  Serial.print("接続中");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("接続完了");

  if ((WiFi.status() == WL_CONNECTED))
  {
    HTTPClient http;
    http.begin("https://www.jma.go.jp/bosai/forecast/data/forecast/130000.json");
    int httpCode = http.GET();

    if (httpCode > 0)
    {
      if (httpCode == HTTP_CODE_OK)
      {
        payload = http.getString();
      }
    }
    if (httpCode <= 0)
    {
      Serial.println("Error on HTTP request");
    }
    http.end(); //リソースを解放
  }
  WiFi.disconnect(true);

  DynamicJsonDocument doc(4096);
  deserializeJson(doc, payload);
  String date = doc[0]["reportDatetime"];
  String forecast = doc[0]["timeSeries"][0]["areas"][0]["weathers"][0];

  Serial.println(date);
  Serial.println(forecast);

  M5.Lcd.setFont(&fonts::lgfxJapanGothic_24);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print(date);

  M5.Lcd.setCursor(0, 30);
  M5.Lcd.print(forecast);
}

void loop()
{
}