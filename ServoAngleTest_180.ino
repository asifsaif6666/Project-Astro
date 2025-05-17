#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm =Adafruit_PWMServoDriver();
#define SERVOMIN 150
#define SERVOMAX 600

int angleToPulse(int angle){
  return map(angle, 0, 180,SERVOMIN, SERVOMAX);
  }


void setup() {
  Serial.begin(9600);
  Serial.println("servo test");
  pwm.begin();
  pwm.setPWMFreq(50);
  delay(10);

}

void loop() {
  
  for(int i=0;i<=90;i++){
    pwm.setPWM(0, 0, angleToPulse(i));
    delay(10);
  }
  Serial.println("Servo 1 90 degree");
  delay(1000);

  for(int i=90;i>=0;i--){
    pwm.setPWM(0, 0, angleToPulse(i));
    delay(10);
  }
  Serial.println("Servo 1 90 degree");
  delay(1000);
  

}
