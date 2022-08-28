#include <AquesTalkTTS.h>
#include <M5Unified.h>
#include <Avatar.h>
#include <tasks/LipSync.h>

using namespace m5avatar;
Avatar avatar;

// AquesTalk のライセンスキー
// NULLや誤った値を指定すると単に無視されます
const char* AQUESTALK_KEY = "XXXX-XXXX-XXXX-XXXX";

void setup() {
  //Serial.begin(115200);
  M5.begin();
  avatar.init(); // start drawing
  avatar.addTask(lipSync, "lipSync");

  //SD.begin(GPIO_NUM_4);
  //TTS.createK(AQUESTALK_KEY);
  TTS.create(AQUESTALK_KEY);
  //TTS.playK("こんにちは、良い天気ですね", 100);
  TTS.play("konnichiwa", 100);
}

void loop() {
}