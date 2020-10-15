#include "Arduino.h"
#include <Servo.h>
#include <ros.h>
#include <std_msgs/Float64.h>

ros::NodeHandle nh;

Servo servo1;
Servo servo2;


float thd0=0,thd1=0,thd2=0;
float phi,ld,l;
float L0=20,L1=80,L2=100;//ロボットアームの諸元
int th0=45,th1=45;//サーボのセット状態(このプログラムをスタートした時ロボットアームが真直ぐ立つようにセットする。)
float y=-16;
float z=6;

void servo_cb(const std_msgs::Float64& cmd_msg){

  //  x=(cmd_msg.data)*1100;
    z=(cmd_msg.data)*100;
    y=-20;
    //digitalWrite(13, HIGH-digitalRead(13));
    digitalWrite(13, HIGH-digitalRead(13));  //toggle led  


}

ros::Subscriber<std_msgs::Float64> sub("z_cdn", servo_cb);

void setup(){

    pinMode(13, OUTPUT);

    nh.initNode();
    nh.subscribe(sub);

    servo1.attach( 5 );
    servo2.attach( 6 );
    
    set_servo();
}

void loop(){
  // Serial.begin(9600);

    nh.spinOnce();
    ik();
    set_servo();
    
  //  Serial.println(th0);
   
    delay(100);

}
void ik(){
  int thb0,thb1;//rad
  
  thb1=acos((z*z+y*y-L1*L1-L2*L2)/(2*L1*L2));
  thb0=acos(z/((L1+L2*cos(thb1))*(L1+L2*cos(thb1))+sin(thb1)*sin(thb1)))+atan2(sin(thb1),(L1+L2*cos(thb1)));

  th1=((thb1+3.14/2)*180)/3.14;
  
  th0=((thb0)*180)/3.14;
}
void set_servo(){
    servo1.write(th0);
    servo2.write(th1);
   
}
