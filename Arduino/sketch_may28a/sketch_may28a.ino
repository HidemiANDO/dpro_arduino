#include <Servo.h>
int SERVO1_SOCKET = 6;
int SERVO2_SOCKET = 5;
int SERVO3_SOCKET = 3;
Servo servo1;
Servo servo2;
Servo servo3;


void setup() {
  // put your setup code here, to run once:
  servo1.attach( SERVO1_SOCKET );
    servo2.attach( SERVO2_SOCKET );
    servo3.attach( SERVO3_SOCKET );
    set_servo();

}
void set_servo(){
    servo1.write(20);
    servo2.write(-60);
    servo3.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
 //set_servo();

}
