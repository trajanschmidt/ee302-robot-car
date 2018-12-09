//L293D
//Motor A
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Motor B
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293

int lightLeft, highL = 0, lowL = 1023;
int lightCenter, highC = 0, lowC = 1023;
int lightRight, highR = 0, lowR = 1023;
int phase = 0;

const int leftSensor = A5;
const int centerSensor = A4;
const int rightSensor = A3;



//This will run only one time.
void setup(){
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4
    //This code  will turn Motor A clockwise for 2 sec.
    Serial.begin(9600);
}
void loop(){

  lightLeft = analogRead(leftSensor);
  lightCenter = analogRead(centerSensor);
  lightRight = analogRead(rightSensor);


  //manualTune();  // manually change the range from light to dark

  //analogWrite(ledPin, lightLevel);

  Serial.println('\n');
  Serial.println("Center");
  Serial.println(lightCenter);
  Serial.println("Left");
  Serial.println(lightLeft);
  Serial.println("Right");
  Serial.println(lightRight);

  delay(1000);

  
}
