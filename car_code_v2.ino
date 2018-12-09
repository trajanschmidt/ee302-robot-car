//L293D
//Motor R
const int forwardR  = 5;  // Pin 14 of L293
const int backwardR  = 6;  // Pin 10 of L293
//Motor L
const int backwardL  = 10; // Pin  7 of L293
const int forwardL  = 9;  // Pin  2 of L293

int lightLeft, highL = 0, lowL = 1023;
int lightCenter, highC = 0, lowC = 1023;
int lightRight, highR = 0, lowR = 1023;
int phase = 0;

const int leftSensor = A5;
const int centerSensor = A4;  //input sensors
const int rightSensor = A3;

const int buzzer = 13; //debug beeps!



//This will run only one time.
void setup(){
    //Set pins as outputs
    pinMode(forwardR, OUTPUT);
    pinMode(backwardR, OUTPUT);
    pinMode(backwardL, OUTPUT);
    pinMode(forwardL, OUTPUT);

   pinMode(forwardL, LOW);
   pinMode(forwardR, LOW);
   pinMode(backwardR, LOW);
   pinMode(backwardL, LOW);
    pinMode(buzzer, OUTPUT); 
    Serial.begin(9600);


}
void loop(){

  lightLeft = analogRead(leftSensor);
  lightCenter = analogRead(centerSensor);
  lightRight = analogRead(rightSensor);

 
  lightLeft = map(lightLeft, 100, 500, 0, 255);
  lightRight = map(lightRight, 20, 100, 0, 255);
  lightCenter = map(lightCenter, 505, 909, 0, 255); 
   
  lightLeft = constrain(lightLeft, 0, 255);
  lightCenter = constrain(lightCenter, 0, 255);
  lightRight = constrain(lightRight, 0, 255);
  //manualTune();  // manually change the range from light to dark

  //analogWrite(ledPin, lightLevel);

  Serial.println("Values:");
  Serial.println(lightLeft);
  Serial.println(lightCenter);
  Serial.println(lightRight);

  


  if(lightLeft<100 && lightRight>100 )  //adjust right
  {
   pinMode(forwardL, HIGH);
   pinMode(forwardR, LOW); 
   pinMode(backwardL, LOW);
   //tone(buzzer, 1000);
   Serial.println("TURN RIGHT!");
   delay(50);
  }
  else if (lightRight<100 && lightLeft>100) //adjust left
  {
   pinMode(forwardL, LOW);
   pinMode(forwardR, HIGH); 
   //tone(buzzer, 500);
   Serial.println("TURN LEFT!");
   delay(50);
  }

  else if (lightLeft<100 && lightCenter < 100) //90 degree
  {
   pinMode(forwardL, HIGH);
   pinMode(backwardR, LOW); 
   pinMode(backwardL, LOW);
    Serial.println("TURN TURN TURN LEFT");
    pinMode(forwardR, LOW);
    delay(500);
  } 
  else
  {
    Serial.println("GO STRAIGHT!");
    pinMode(forwardL, LOW);
    pinMode(backwardL, HIGH);
    pinMode(forwardR, LOW);
    pinMode(backwardR, HIGH); 
    //tone(buzzer, 2000);
    
  }

  

  
  
  
}