#include "Arduino.h"
#include <Servo.h>
#include <ros.h>
#include <std_msgs/Float64.h>
Servo servo1;
Servo servo2;


void setup() {
  // put your setup code here, to run once:
servo1.attach( 5 );
    servo2.attach( 6 );
        servo1.write(70);
    servo2.write(-(50));
   
}

void loop() {
  // put your main code here, to run repeatedly:
    servo1.write(70);
    servo2.write(-50);
   
}
