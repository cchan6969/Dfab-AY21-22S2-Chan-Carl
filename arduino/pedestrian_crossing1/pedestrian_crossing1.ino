// Pedestrian Crossing Simulation
//  RedLED - D7   (1: ON, 0: OFF)
//  GreenLED - D6 (1: ON, 0: OFF)
//  PB - D2 (OPEN: 1, CLOSED: 0)
//
// Steven Chew
// Date: 2022-01-21
//

// Declare LED, PB pins
#define rled 7
#define gled 6
#define pb 2

// Declare variables
const int rDelay = 5000;	// 5s delay after PB pressed
const int gDelay = 6000;	// Green man for 6s

void setup()
{
  pinMode(rled, OUTPUT);	// configure led pins as output
  pinMode(gled, OUTPUT);
  pinMode(pb, INPUT);		// configure switch pin as input
  Serial.begin(9600);		// serial baudrate
  
  // Start condition: DONT WALK
  digitalWrite(rled, HIGH);
  digitalWrite(gled, LOW);
  Serial.println("DON'T WALK");
}

void loop()
{
  // wait for switch to be pressed
  if (digitalRead(pb) == LOW){
    delay(15);		// 15ms delay for debounce
    while (digitalRead(pb) == LOW);	// wait for switch release
    delay(rDelay);	// maintain DONT WALK for 5s
    // Show WALK indicator
    digitalWrite(rled, LOW);
    digitalWrite(gled, HIGH);
    Serial.println("WALK");
    delay(gDelay);	// maintain WALK state for 6s
    // revert to DONT WALK state
    digitalWrite(gled, LOW);
    digitalWrite(rled, HIGH);
    Serial.println("DON'T WALK");
  }
}
