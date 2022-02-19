#include <Servo.h>    // include servo library header file

Servo l; // create servo object to control servo
Servo s; // create servo object to control servo

int lClose = 180;  // servo motor PWM position 
int lOpen = 100;   // servo motor PWM position 

//int sClose = 0;   
int sClose = 0;  // servo motor PWM position 
int sOpen = 110;   // servo motor PWM position 

int b = 0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(4,INPUT);
  l.attach(2); // set servo motor output pwn signal pin
  s.attach(3); // set servo motor output pwn signal pin  



  l.write(lClose);
  s.write(sClose);
  Serial.begin(9600);  
}

void loop() 
{
  // put your main code here, to run repeatedly
  b = digitalRead(4);
  if (b == LOW)
  {
    Serial.println("low"); 
  }   

  
  else if (b == HIGH)
  {
    Serial.println("high");
    
    l.write(lOpen);       // output servo position
    delay(1000);

    s.write(sOpen);      // output servo position
    delay(500);

    s.write(sClose);       // output servo position
    delay(1000);

    l.write(lClose);      // output servo position
    delay(1000);
    
  }
}
