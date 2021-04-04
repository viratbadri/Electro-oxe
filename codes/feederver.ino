#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include "HX711.h"
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>  
int servoPin = 5; 
Servo Servo1;
#define DOUT   14
#define CLk    12
#define buzzer 13
HX711 scale;
int   weight;
float calibration_factor = -706600.00;
char auth[] = "TB76AddbGwniz5i_wQpzayylJvfSUB9d";
char ssid[] = "lg v30+";
char pass[] = "123455678";
int show;
int slval;
int btnval;




BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable(food weight)
  slval = pinValue;
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable(switch)
  btnval = pinValue;
  Serial.println("V2 value is: \n");
  Serial.println(pinValue);
  Serial.print("V1 Slider value is:\n");
  Serial.println(slval);
}


void setup()
{
  // Debug console
  pinMode(13, OUTPUT);//buzzer
  Serial.begin(9600);
  scale.begin(DOUT,CLk);
  
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  long zero_factor = scale.read_average();
  Servo1.attach(servoPin); 

  Blynk.begin(auth, ssid, pass);
  WiFi.begin(ssid, pass);
  {
  delay(1000);
  Serial.print(".");
 
  }
  Serial.println("");
  Serial.println("WiFi connected"); 
  delay(2000);
 
   //timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  weight = scale.get_units()*1000;
  Serial.println("weight \n ");
  Serial.print(weight);
  Serial.print(" g");
  Blynk.virtualWrite(V3, weight);
  if(btnval==HIGH){
     Servo1.write(180);
     show=1;
  }
   if(weight>=slval)
      { Servo1.write(-180);
        show=0;
      }
   Blynk.virtualWrite(V5,show);
   if (show == 1){
    digitalWrite(buzzer,HIGH);
    }
   else 
     digitalWrite(buzzer,LOW);
  
  
}
