// C++ code
//
#include <Servo.h>
Servo lid; //name of servo for lifting lid
Servo arm; //name of servo for flicking switch


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
  pinMode(Switch,INPUT);
  lid.attach(2);
  arm.attach(3);
  Serial.begin(9600);

  // Servo Default Starting Position
  arm.write(a);
  lid.write(b);
}

void loop() 
{

// Action Selection starting with 1

  if (digitalRead(Switch) == HIGH)
  {
    if (action > 8) 
    {
      action = 1;
  }  
    
    if (action == 1) 
    {
      action1();
    }
    
    else if (action == 2) 
    {
      action2();
    }
     
    else if (action == 3) 
    {
      action3();
    }
    else if (action == 4) 
    {
      action4();
    }
    else if (action == 5) 
    {
      action5();
    }
    else if (action == 6) 
    {
      action6();
    }
    else if (action == 7) 
    {
      action7();
    }
    

    action += 1;
    
  }
}

//The Following are actions that are chosen chronologically

void action1() 
// slow open lid, extend arm, close arm, close lid (checked)
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

void action2() 
// fast open lid, extend arm, close arm, close lid  
{
  lid.write(d);
  delay(100);
  
  arm.write(c+10);
  delay(250);
  
  arm.write(a);
  delay(100);
  
  lid.write(b);
}

void action3()
// slowly open lid, fast arm extend, retract and lid close
{
    for(pos = b; pos > f; pos -=1)
    {
      lid.write(pos);
      delay(50);
    }
  arm.write(c+10);
    delay(250);
  
    arm.write(a);
    delay(100);
  
    lid.write(b);
}

void action4() 
// open lid and hold extend arm for awhile, slow retract and fast lid close
{
    delay(250);
    lid.write(d);
  
    delay(100);
    arm.write(c);
  
    delay(2500);
  
  for(pos = c; pos > a; pos -=1)
    {
      arm.write(pos);
      delay(50);
    }
    lid.write(b);
    arm.write(a);
}

void action5() 
// jebaiting with opening and closing lid, then extend and retract arm
{
  lid.write(d);
  delay(500);
  
  lid.write(b);
  delay(500);
  
  lid.write(d);
  delay(500);
  
  lid.write(b);
  delay(500);
  
  lid.write(d);
  delay(500);
  
  lid.write(b);
  delay(2500);
  
  lid.write(d);
  delay(100);
  
  arm.write(c);
  delay(250);
  
  arm.write(a);
  delay(100);
  
  lid.write(b);
}

void action6() 
// machine gun rapid open lid, extend arm to alomost touching, retract arm, and finally extend full and close close lid
{
  lid.write(d);
  delay(100);
  
  arm.write(e);
  delay(250);
  
  arm.write(a);
  delay(100);
  
  lid.write(b);
  delay(250);
  
  lid.write(d);
  delay(100);
  
  arm.write(e);
  delay(250);
  
  arm.write(a);
  delay(100);
  
  lid.write(b);
  delay(250);
  
  lid.write(d);
  delay(100);
  
  arm.write(e);
  delay(250);
  
  arm.write(a);
  delay(100);
  
  lid.write(b);
  delay(250); 
  
  lid.write(d);
  delay(100);
  
  arm.write(c+15);
  delay(250);
  
  arm.write(a);
  delay(100);
  
  lid.write(b);
  delay(500);
}

void action7() 
//menacing slowly lid open, arm extend, arm retract, lid close
{
    for(pos = b; pos > d; pos -=2)
    {
      lid.write(pos);
      delay(50);
  }
  
  for(pos = a; pos < c + 10; pos +=2)
    {
      arm.write(pos);
      delay(100);
    }
  
    arm.write(c + 10);
  
  for(pos = c + 10; pos > a; pos -=2)
    {
      arm.write(pos);
      delay(100);
    }
  
  for(pos = d; pos < b; pos +=2)
    {
      lid.write(pos);
      delay(50);
    }
  
    lid.write(b);
}
