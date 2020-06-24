#define joyX A0
#define joyY A1
void setup() 
{
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);
}
void loop() {
int xValue = analogRead(joyX);
int yValue = analogRead(joyY);
Serial.print(xValue);
Serial.print("\t");
Serial.println(yValue);
if (xValue<=250 && yValue<=512)
{
digitalWrite(8, HIGH);
Serial.println("left");
}
else{digitalWrite(8, LOW);}

if (xValue>=800 && yValue<=750)
{
digitalWrite(10, HIGH);
Serial.println("right");
}
else{digitalWrite(10, LOW);}

if (xValue<=750 && yValue<=250)
{
digitalWrite(11, HIGH);
Serial.println("top");
}
else{digitalWrite(11, LOW);}

if (xValue<=750 && yValue>=750)
{
digitalWrite(9, HIGH);
Serial.println("bottom");
}
else
{
  digitalWrite(9, LOW);
}
}
