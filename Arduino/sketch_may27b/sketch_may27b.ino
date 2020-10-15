#include "Arduino.h"
#include <Servo.h>
#include <ros.h>
#include <std_msgs/Float64.h>

ros::NodeHandle nh;

Servo servo1;
Servo servo2;


float thd0=0,thd1=0,thd2=0;
float phi,ld,l;
float Lo=0,L1=20,L2=106,L3=460;//ロボットアームの諸元
int th0o=0,th1o=144,th2o=165;//サーボのセット状態(このプログラムをスタートした時ロボットアームが真直ぐ立つようにセットする。)
float x,y,z;

void servo_cb(const std_msgs::Float64& cmd_msg){

    x=cmd_msg.data;
    y=0;
    digitalWrite(13, HIGH-digitalRead(13));

}

ros::Subscriber<std_msgs::Float64> sub("servo", servo_cb);

void setup(){

    pinMode(13, OUTPUT);

    nh.initNode();
    nh.subscribe(sub);

    servo1.attach( 3 );
    servo2.attach( 5 );
    
    set_servo();
}

void loop(){

    nh.spinOnce();
    delay(1);

}
void ik(){
  float phi,ld,l,th0,th1,th2;
  th0=atan2(y,x);
  l=sqrt(x*x + y*y);
  ld=sqrt((l-L1)*(l-L1) + (z-Lo)*(z-Lo));
  phi=atan2((z-Lo),l-L1);
  th1=-3.14/2 + phi + acos((ld*ld+L2*L2-L3*L3)/(2*ld*L2));
  th2=-3.14 + acos((L2*L2+L3*L3-ld*ld)/(2*L2*L3));
  thd0=th0*180/3.14;
  thd1=th1*180/3.14;
  thd2=th2*180/3.14;
}
void set_servo(){
    servo1.write(th0o+thd0);
    servo2.write(-(th1o+thd1));
   
}
