#include <VarSpeedServo.h> 
VarSpeedServo myservo1;
VarSpeedServo myservo2;

const int servoPin1 = 6; // the digital pin used for the first servo
const int servoPin2 = 5;

void setup() {
  myservo1.attach(servoPin1);  // attaches the servo on pin 9 to the servo object
  myservo1.write(0,255,false); // set the intial position of the servo, as fast as possible, run in background
  myservo2.attach(servoPin2);  // attaches the servo on pin 9 to the servo object
  myservo2.write(0,255,true);  // set the intial position of the servo, as fast as possible, wait until done
  Serial.begin(9600);
}

void loop() {
   int sensorValue = analogRead(A0);

if(sensorValue  < 600){
  myservo1.write(30,100,false);
  myservo2.write(150,100,true);
  delay(3000);
}else{
  myservo1.write(0,100,false);
  myservo2.write(179,100,true);
  
}

 Serial.println(sensorValue);
}
