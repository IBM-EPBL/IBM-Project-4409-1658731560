// C++ code
//
void setup()
{
 pinMode(8,OUTPUT);
 pinMode(5,OUTPUT);
 Serial.begin(9600);
}

void loop()
{
  int a=analogRead(A0);
  int b=analogRead(A3);
  if(a>100)
  {
    digitalWrite(8,HIGH);
    Serial.println("motion detected");
  }
  else
  {
    digitalWrite(8,LOW);
    Serial.println("motion not detected");
  } 
  if(b>300)
  {
    digitalWrite(5,HIGH);
    Serial.println("gas leakage detected");
  }
  else
  {
    digitalWrite(5,LOW);
    Serial.println("gas leakage not detected");
  }
  delay(1000);
} 