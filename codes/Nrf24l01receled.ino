#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define led1 A0
#define led2 A1
int buttonState ;

RF24 radio(9, 8); // CE, CSN
const byte address[6] = "00002";

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  radio.startListening();
 if(radio.available());{
    radio.read(&buttonState, sizeof(buttonState));
//    Serial.println("IN");
  Serial.println(buttonState);

  if (buttonState == 1) {
    digitalWrite(led1, LOW);
  }
  else  if (buttonState == 2) {
    digitalWrite(led1, HIGH);
  }
  else if (buttonState == 3) {
    digitalWrite(led2, LOW);
  }
  else  if (buttonState == 4) {
    digitalWrite(led2, HIGH);
  }
 }
 
}
