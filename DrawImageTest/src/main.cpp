#include <M5Unified.h>

void setup() {
  SPIFFS.begin();
  SD.begin(GPIO_NUM_4);

  auto cfg = M5.config();
  M5.begin(cfg);
}

void loop() {
  M5.update();
  if (M5.BtnA.wasClicked())
  {
    M5.Lcd.clear();
    const char *filePath = "/sunny.jpg";    // SDカードにsunny.jpgをコピーしておく
    M5.Lcd.drawJpgFile(SD, filePath, 0, 0);
  }
  else if (M5.BtnB.wasClicked())
  {
    M5.Lcd.clear();
    const char *filePath = "/cloudy.bmp";
    M5.Lcd.drawBmpFile(SPIFFS, filePath, 50, 50);
  }
  else if (M5.BtnC.wasClicked())
  {
    M5.Lcd.clear();
    const char *filePath = "/rainy.png";
    M5.Lcd.drawPngFile(SPIFFS, filePath, 100, 100);
  }
}