#include <Servo.h>    // include servo library header file

Servo servo1; // create servo object to control servo
Servo servo2; // create servo object to control servo

int Close = 110;  // servo motor PWM position 
int Open = 150;   // servo motor PWM position 


void setup() 
{
  // put your setup code here, to run once:
  pinMode(4,INPUT);
  servo1.attach(2); // set servo motor output pwn signal pin
  servo2.attach(3); // set servo motor output pwn signal pin  

  servo1.write(50);
  servo2.write(90);
  Serial.begin(9600);  
}

void loop() 
{
  // put your main code here, to run repeatedly
  if (digitalRead(4) == HIGH){
  Serial.println("high"); }   

  if (digitalRead(4) == LOW){
  Serial.println("low"); }   
//  
  if (digitalRead(4) == HIGH)
  {
    servo1.write(Open);       // output servo position
    delay(1000);

    servo1.write(Close);      // output servo position
    delay(1000);

    servo2.write(Open);       // output servo position
    delay(1000);

    servo2.write(Close);      // output servo position
    delay(1000);
  }
}
