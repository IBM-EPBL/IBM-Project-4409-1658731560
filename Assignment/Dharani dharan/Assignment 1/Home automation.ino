#include <Servo.h>

int LightSensorVal = 0; 
int PIRSensorVal = 0;   
int RelayOutputVal = 0;  
const int gas =0;
float sensorvalue = 0;
Servo servo_12;
long duration=0;
float distanceCm, distanceInch;

void setup()
{
  pinMode(A0, INPUT); 
  pinMode(2, INPUT);  
  pinMode(8, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(4, INPUT); 
  pinMode(A1, INPUT);
  servo_12.attach(12);
  
  Serial.begin(9600);

}

void loop()
{
  LightSensorVal = analogRead(A0);
  PIRSensorVal = digitalRead(2);
  if (LightSensorVal < 600) {
    if (PIRSensorVal == HIGH) {
      digitalWrite(8, HIGH);
      delay(10000);
    } else {
      digitalWrite(8, LOW);
      delay(1000); 
    }
  } else {
    digitalWrite(8, LOW);
    Serial.println(LightSensorVal);
    delay(300); 
  }
  

  sensorvalue = analogRead(A1);
  if(sensorvalue >= 470){
    tone(3,255,255);
    Serial.println(" |SMOKE DETECTED");
    
  
  }

  digitalWrite(7, LOW);
  delayMicroseconds(10);
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  duration = pulseIn(4, HIGH);
  distanceCm= duration*0.034/2;
  Serial.println(distanceCm);
  if(distanceCm<=100){
  	servo_12.write(190);
    delay(5000);
    servo_12.write(90);
  }
}