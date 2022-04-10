# PCA9685_servo_control
A easy way to control many servos using PCA9685.

   Adafruit 16-Channel 12bit PWM/Servo Driver - I2C Interface - PCA9685
   www.github.com/adafruit/Adafuit-PWM-Servo-Driver-Library

      pros:
      uses only 2 pins (to communicate via I2C)
      total control of the movement speed
      
      cons:
      must know the actual or last position of the servo.
      
      Depending of the aplication you can use the servo library <servo.h>
      and use readMicroseconds() to read the actual position.
      For this case, check my github.

