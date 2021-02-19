#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define buttonPin1 3
#define buttonPin2 4

int buttonState1 ;
int buttonState2;

RF24 radio(9, 8); // CE, CSN

const byte address[6] = "00002";

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  buttonState1 = digitalRead(buttonPin1);
  Serial.print("buttonState1");
  Serial.println(buttonState1 );
  Serial.print("\n");
  buttonState2 = digitalRead(buttonPin2);
  Serial.print("buttonState2 ");
  Serial.println(buttonState2 );
  Serial.print("\n");

  if (buttonState1 == 1)
  {
    buttonState1 = 1;
  }
  else  if (buttonState1 == 0)
  {
    buttonState1 = 2;
  }
  if (buttonState2 == 1)
  {
    buttonState2 = 3;
  }
  else  if (buttonState2 == 0)
  {
    buttonState2 = 4;
  }
  radio.write(&buttonState1, sizeof(buttonState1));
  radio.write(&buttonState2, sizeof(buttonState2));
}
