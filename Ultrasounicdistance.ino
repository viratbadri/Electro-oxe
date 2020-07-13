#include <LiquidCrystal.h> 
const int rs = 7, en = 6 ,d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
const int trigPin = 11;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;
void setup() {
lcd.begin(16,2);
Serial.begin(9600); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
lcd.begin(16, 2);
for(int i=1;i>=-16;i--)
{
  lcd.clear();
  lcd.setCursor(i,0);
  lcd.print(" Welcome to Electro Oxe");
  delay(300);
}
delay(1000);
lcd.clear();
lcd.print ("Ultrasonic range");
lcd.setCursor(0,1);
lcd.print ("   cm & inch");
delay (5000);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration * 0.01330 / 2;
lcd.setCursor(0,0); 
lcd.print("Distance= ");
lcd.print(distanceCm);
Serial.println(distanceCm); 
lcd.print(" cm ");
delay(10);
lcd.setCursor(0,1);
lcd.print("Distance= ");
lcd.print(distanceInch);
Serial.println(distanceInch);
lcd.print(" inch ");
delay(10);
}
