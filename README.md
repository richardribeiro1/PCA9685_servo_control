# PCA9685_servo_control
A easy way to control many servos using PCA9685.

   Adafruit 16-Channel 12bit PWM/Servo Driver - I2C Interface - PCA9685
   https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library
   
   ![image](https://user-images.githubusercontent.com/65542005/162625088-20aa34f3-aea3-40ab-87da-a1c78eb15f1d.png)

      Pros:
      - Uses only 2 pins to control 16+ servos (communicate via I2C)
      - Total control of the movement speed and range
      
      Cons:
      - Must know the actual or last position of the servo.
      
      Depending of the aplication you can use the servo library <servo.h>
      and use readMicroseconds() to read the actual position.
      For this case, check my github.
