
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */

LedControl lc=LedControl(12,11,10,1);
int button =9;
/* we always wait a bit between updates of the display */
unsigned long delaytime=500;
  byte six[8]={B00000000,B11011011,B11011011,B00000000,B00000000,B11011011,B11011011,B00000000};
  byte five[8]={B00000000,B01100110,B01100110,B00011000,B00011000,B01100110,B01100110,B00000000};
  byte four[8]={B00000000,B01100110,B01100110,B00000000,B00000000,B01100110,B01100110,B00000000};
  byte three[8]={B11000000,B11000000,B00000000,B00011000,B00011000,B00000000,B00000011,B00000011};
  byte two[8]={B00000000,B00000000,B00000000,B01100110,B01100110,B00000000,B00000000,B00000000};
  byte one[8]={B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  pinMode(button,INPUT);
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,14);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
 This method will display the characters
 (you need at least 7x7 leds to see the whole chars)
 */
void one1() {
  /* here is the data for the characters */
  
  /* now display them one by one with a small delay */
  lc.setRow(0,0,one[0]);
  lc.setRow(0,1,one[1]);
  lc.setRow(0,2,one[2]);
  lc.setRow(0,3,one[3]);
  lc.setRow(0,4,one[4]);
  lc.setRow(0,5,one[5]);
  lc.setRow(0,6,one[6]);
  lc.setRow(0,7,one[7]);
  
  delay(delaytime);
}
void two2() {
  /* here is the data for the characters */
  
  /* now display them one by one with a small delay */
  lc.setRow(0,0,two[0]);
  lc.setRow(0,1,two[1]);
  lc.setRow(0,2,two[2]);
  lc.setRow(0,3,two[3]);
  lc.setRow(0,4,two[4]);
  lc.setRow(0,5,two[5]);
  lc.setRow(0,6,two[6]);
  lc.setRow(0,7,two[7]);
  
  delay(delaytime);
}
void three3() {
  /* here is the data for the characters */
  
  /* now display them one by one with a small delay */
  lc.setRow(0,0,three[0]);
  lc.setRow(0,1,three[1]);
  lc.setRow(0,2,three[2]);
  lc.setRow(0,3,three[3]);
  lc.setRow(0,4,three[4]);
  lc.setRow(0,5,three[5]);
  lc.setRow(0,6,three[6]);
  lc.setRow(0,7,three[7]);
  
  delay(delaytime);
}
void four4() {
  /* here is the data for the characters */
  
  /* now display them four by four with a small delay */
  lc.setRow(0,0,four[0]);
  lc.setRow(0,1,four[1]);
  lc.setRow(0,2,four[2]);
  lc.setRow(0,3,four[3]);
  lc.setRow(0,4,four[4]);
  lc.setRow(0,5,four[5]);
  lc.setRow(0,6,four[6]);
  lc.setRow(0,7,four[7]);
 
  delay(delaytime);
}
void five5() {
  /* here is the data for the characters */
  
  /* now display them five by five with a small delay */
  lc.setRow(0,0,five[0]);
  lc.setRow(0,1,five[1]);
  lc.setRow(0,2,five[2]);
  lc.setRow(0,3,five[3]);
  lc.setRow(0,4,five[4]);
  lc.setRow(0,5,five[5]);
  lc.setRow(0,6,five[6]);
  lc.setRow(0,7,five[7]);

  delay(delaytime);
}
void six6() {
  /* here is the data for the characters */
  
  /* now display them six by six with a small delay */
  lc.setRow(0,0,six[0]);
  lc.setRow(0,1,six[1]);
  lc.setRow(0,2,six[2]);
  lc.setRow(0,3,six[3]);
  lc.setRow(0,4,six[4]);
  lc.setRow(0,5,six[5]);
  lc.setRow(0,6,six[6]);
  lc.setRow(0,7,six[7]);
  
  delay(delaytime);
}


void loop() { 
  int x ;
  if(digitalRead(button)== HIGH )
{
 x = random(1,7);

switch(x){
case 1 : one1();
break;
case 2 : two2();
break;
case 3 : three3();
break;
case 4 : four4();
break;
case 5 : five5();
break;
case 6 : six6();
break;}
}
}
