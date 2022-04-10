/* Created by Richard Ribeiro
    richard.ribeiro1@gmail.com

   Code to be used to Adafruit 16-Channel 12bit PWM/Servo Driver - I2C Interface - PCA9685
   www.github.com/adafruit/Adafuit-PWM-Servo-Driver-Library

*/

#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

#define SERVO_FREQ 50 // 50Hz - from datasheet of the servo

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); //default address 0x40

void setup() {
  pwm.begin(); //PCA9685 HW-170 PWM
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(300); //voltage stabilize
  homing(); //set a initial position
}

void loop() {
  servoControl(1, 1700, 2300, 10); //define servo 1 from 1700 to 2300 with a speed of 10
  servoControl(0, 800, 2000, 5); //define servo 0 from 800 to 2000 with a speed of 5
  servoControl(1, 2300, 1000, 15); //define servo1 from 2300 to 1000 with a speed of 15
  servoControl(0, 2000, 670, 7) //define servo from 2000 to 670 with a speed of 7

  /*
     this function is useful when you want to control de speed of movement using the PCA9685
      pros:
      uses only 2 pins (to communicate via I2C)
      total control of the movement speed

      cons:
      must know the actual or last position of the servo.

      Depending of the aplication you can use the servo library <servo.h>
      and use readMicroseconds() to read the actual position.
      For this case, check my github.
      www.github.com/richardribeiro1
  */
  
}

//Homing function is important to set a default position
void homing() {
  pwm.writeMicroseconds(0, 800);
  delay(500); //waiting position
  pwm.writeMicroseconds(1, 1700);
  delay(500); //waiting position
  pwm.writeMicroseconds(2, 2000);
  delay(500); //waiting position
  pwm.writeMicroseconds(3, 1000);
  delay(500); //waiting position
}

//servoControl function is used to control every servo in the PCA9685
void servoControl(int servonum, int posInitial, int posFinal, int speed) {
  int position;
  position = posInitial;

  if (posInitial < posFinal) { //increasing
    for (position; position < posFinal; position += speed) {
      if (position >= posFinal - speed) { //avoid overflow
        pwm.writeMicroseconds(servonum, posFinal);
        delay(5);
      }
      else {
        pwm.writeMicroseconds(servonum, position);
        delay(5);
      }
    }
  }
  else { //decreasing
    for (position; position > posFinal; position -= speed) {
      if (position <= posFinal + speed) { //avoid overflow
        pwm.writeMicroseconds(servonum, posFinal);
        delay(5);
      }
      else {
        pwm.writeMicroseconds(servonum, position);
        delay(5);
      }
    }
  }
}
