#include <Arduino.h>
#include <ServoEasing.hpp>

ServoEasing servo1;

void setup() { 
  Serial.begin(115200);
  servo1.attach(G5, 90, 500, 2400);
  servo1.setEasingType(EASE_QUADRATIC_IN_OUT);
}

void loop() {
  servo1.setEaseToD(90, 2000);
  synchronizeAllServosStartAndWaitForAllServosToStop();
  delay(3000);
  servo1.setEaseToD(120, 2000);
  synchronizeAllServosStartAndWaitForAllServosToStop();
  delay(3000);
  servo1.setEaseToD(90, 2000);
  synchronizeAllServosStartAndWaitForAllServosToStop();
  delay(3000);
  servo1.setEaseToD(60, 2000);
  synchronizeAllServosStartAndWaitForAllServosToStop();
  delay(3000);
}


/* LEDC
void setup() { 
  Serial.begin(115200);
  ledcSetup(0, 50, 8);
  ledcAttachPin(G5, 0);
}
void loop() {
  ledcWrite(0, 15);
}
*/

/* ESP32Servo
#include <ESP32Servo.h>

Servo servo1;

void setup() { 
  Serial.begin(115200);
  servo1.setPeriodHertz(50);
  servo1.attach(G5, 500, 2400);
}

void loop() {
  servo1.write(90);
}
*/