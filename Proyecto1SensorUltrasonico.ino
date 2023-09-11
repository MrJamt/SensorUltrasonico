int GREEN_LED = 33;
int YELLOW_LED1 = 25;
int YELLOW_LED2 = 26;
int RED_LED = 27;


int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED1, OUTPUT);
  pinMode(YELLOW_LED2, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void setLedState(int greenState, int yellow1State, int yellow2State, int redState)
{
    digitalWrite(GREEN_LED,greenState);
  	digitalWrite(YELLOW_LED1,yellow1State);
  	digitalWrite(YELLOW_LED2,yellow2State);
    digitalWrite(RED_LED,redState);
}

void loop()
{
  cm = 0.01723 * readUltrasonicDistance(14, 12);    // measure the ping time in cm
  Serial.print(cm);
  Serial.println("cm");
  delay(100);   // Wait for 100 millisecond(s)
  
  if (cm<5) {
  	setLedState(HIGH,LOW,LOW,LOW);
  }
  else if(cm<10)
  {
    setLedState(LOW,HIGH,LOW,LOW);
  }
  else if(cm<15)
  {
   setLedState(LOW,LOW,HIGH,LOW);
  }
  else
  {
   setLedState(LOW,LOW,LOW,HIGH);
  }
  delay(100);
}
