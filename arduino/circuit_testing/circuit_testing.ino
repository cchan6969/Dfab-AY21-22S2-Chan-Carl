#include <Servo.h>    // include servo library header file

Servo lid; // create servo object to control servo
Servo arm; // create servo object to control servo

int Switch= 4;

int action = 1;

int pos = 0;

int a = 0;  //arm retract 0

int b = 180;  //lid close 180

int c = 110; //arm extend 110

int d = 100;  //lid fully open 100

int e = c-20; //arm almost full extend 90

int f= 180-d/2; //half lid 130


void setup() 
{
  // put your setup code here, to run once:
  pinMode(Switch,INPUT);
  lid.attach(2); // set servo motor output pwn signal pin
  arm.attach(3); // set servo motor output pwn signal pin  



  arm.write(a);
  lid.write(b);
  Serial.begin(9600);  
}

void loop() 
{
  // put your main code here, to run repeatedly
   if (digitalRead(Switch) == HIGH)
  {
    lid.write(f);
  delay(1000);
  
  arm.write(c);
  delay(500); 
  
  arm.write(a);
  delay(1000);
  
  lid.write(b);
  delay(1000);
  }
}
