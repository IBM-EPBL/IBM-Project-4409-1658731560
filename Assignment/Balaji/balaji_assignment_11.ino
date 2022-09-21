// C++ code
//
void setup()
{
  pinMode(7, OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int a=analogRead(A0);
  int b=analogRead(A1);
  int c=analogRead(A2);
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  if(a<=500 && b>=300)
  {
     digitalWrite(7,HIGH);
  }
  else
  {
    digitalWrite(7,LOW);
  }
  if(c>=150)
  {
     digitalWrite(6,HIGH);
  }
  else
  {
    digitalWrite(6,LOW);
  }
  
  delay(1000);
}