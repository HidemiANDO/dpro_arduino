void setup()
{
  pinMode(3, OUTPUT);//1tousei
  pinMode(5, OUTPUT);//2tousei
  pinMode(6, OUTPUT);//3tousei
}

void loop()
{
   analogWrite(3, 200);
   analogWrite(5, 150);
   analogWrite(6, 100);
   delay(100);
   analogWrite(3, 180);
   analogWrite(5, 130);
   analogWrite(6, 80);
   delay(100);
   analogWrite(3, 150);
   analogWrite(5, 100);
   analogWrite(6, 50);
   delay(300);
   analogWrite(3, 180);
   analogWrite(5, 130);
   analogWrite(6, 80);
   delay(100);
}
