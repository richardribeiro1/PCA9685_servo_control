# PCA9685_servo_control
A easy way to control many servos using PCA9685.

   Adafruit 16-Channel 12bit PWM/Servo Driver - I2C Interface - PCA9685
   
   https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library
 
   <img src="https://user-images.githubusercontent.com/65542005/162625448-4540828a-d6cf-48cf-ae85-06361de72a86.png"
        data-canonical-src="https://user-images.githubusercontent.com/65542005/162625448-4540828a-d6cf-48cf-ae85-06361de72a86.png" width="400" height="400" />

   
      Pros:
      - Uses only 2 pins to control 16+ servos (communicate via I2C)
      - Total control of the movement speed and range
      
      Cons:
      - Must know the actual or last position of the servo.
      
      Depending of the aplication you can use the servo library <servo.h> and use readMicroseconds() to read the actual position.
      For this case, check my github.
