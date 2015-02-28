#include <RedBot.h>
#include <RedBotSoftwareSerial.h>

RedBotMotor motors;
long turnCalibration = 0.7978;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(2000);
  turnToAngle(90);
  delay(2000);
}

void turnToAngle(int angle) {
  long turningSpeed;
  turningSpeed = (long) 180 * turnCalibration;
  
  long turningTime;
  turningTime = (long) 1000 * angle / turningSpeed;
  
  motors.pivot(100);
  delay(turningTime);
  motors.brake();
}
