// C++ code
//
#include <Servo.h>
Servo lid; //name of servo for lifting lid
Servo arm; //name of servo for flicking switch


int Switch= 4;

int action = 1;

int pos = 0;

int a = 50;  //arm retract

int b = 90;  //lid close

int c = 177; //arm extend

int d = 50;  //lid open

int e = 155; //arm almost full extend
void setup() 
{
  pinMode(Switch,INPUT);
  lid.attach(2);
  arm.attach(3);
  Serial.begin(9600);

  // Servo Default Starting Position

  arm.write(50);
  lid.write(90);
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
// slow open lid, extend arm, close arm, close lid
{
  lid.write(20);
  delay(1000);
  
  arm.write(c);
  delay(500); 
  
  arm.write(50);
  delay(1000);
  
  lid.write(90);
  delay(1000);
}

void action2() 
// fast open lid, extend arm, close arm, close lid  
{
  lid.write(50);
  delay(100);
  
  arm.write(c);
  delay(250);
  
  arm.write(50);
  delay(100);
  
  lid.write(90);
}

void action3()
// slowly open lid, fast arm extend, retract and lid close
{
    for(pos = 90; pos > 20; pos -=1)
    {
      lid.write(pos);
      delay(50);
    }
  arm.write(c);
    delay(250);
  
    arm.write(50);
    delay(100);
  
    lid.write(90);
}

void action4() 
// open lid and hold extend arm for awhile, slow retract and fast lid close
{
  delay(250);
    lid.write(50);
  
    delay(100);
  arm.write(c);
  
    delay(2500);
  
  for(pos = c; pos > 90; pos -=1)
    {
      arm.write(pos);
      delay(50);
    }
    lid.write(90);
    arm.write(50);
}

void action5() 
// jebaiting with opening and closing lid, then extend and retract arm
{
  lid.write(50);
  delay(500);
  
  lid.write(90);
  delay(500);
  
  lid.write(50);
  delay(500);
  
  lid.write(90);
  delay(500);
  
  lid.write(50);
  delay(500);
  
  lid.write(90);
  delay(2500);
  
  lid.write(50);
  delay(100);
  
  arm.write(c);
  delay(250);
  
  arm.write(50);
  delay(100);
  
  lid.write(90);
}

void action6() 
// machine gun rapid open lid, extend arm to alomost touching, retract arm, and finally extend full and close close lid
{
  lid.write(50);
  delay(100);
  
  arm.write(155);
  delay(250);
  
  arm.write(50);
  delay(100);
  
  lid.write(90);
  delay(250);
  
  lid.write(50);
  delay(100);
  
  arm.write(155);
  delay(250);
  
  arm.write(50);
  delay(100);
  
  lid.write(90);
  delay(250);
  
  lid.write(50);
  delay(100);
  
  arm.write(155);
  delay(250);
  
  arm.write(50);
  delay(100);
  
  lid.write(90);
  delay(250); 
  
  lid.write(50);
  delay(100);
  
  arm.write(c);
  delay(250);
  
  arm.write(50);
  delay(100);
  
  lid.write(90);
}

void action7() 
//menacing slowly lid open, arm extend, arm retract, lid close
{
    for(pos = 90; pos > 20; pos -=2)
    {
      lid.write(pos);
      delay(50);
  }
  
  for(pos = 50; pos < 145; pos +=2)
    {
      arm.write(pos);
      delay(100);
    }
  
    arm.write(c);
  
  for(pos = c; pos > 50; pos -=2)
    {
      arm.write(pos);
      delay(100);
    }
  
  for(pos = 20; pos < 90; pos +=2)
    {
      lid.write(pos);
      delay(50);
    }
  
    lid.write(90);
}
