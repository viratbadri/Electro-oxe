/*
 The Cuicuit:
  BUTTON CONNECTIONS
  
 BUTTON [SELECT] to D8
 BUTTON [UP]     to D9
 BUTTON [DOWN]   to D10

   LCD CONNECTIONS  
 LCD D7 pin to D2
 LCD Vee tied to a pot to control brightness
 LCD Vss and R/W tied to ground
 LCD Vcc to +5V 
 */
#include <LiquidCrystal.h>


// initialize the interface pins
LiquidCrystal lcd(2,3,4,5,6,7);
int s,m,h,a,d,state,state1,state2,dg,cnt;

// the 8 arrays that form each segment of the custom numbers
byte bar1[8] = 
{
        B11100,
        B11110,
        B11110,
        B11110,
        B11110,
        B11110,
        B11110,
        B11100
};
byte bar2[8] =
{
        B00111,
        B01111,
        B01111,
        B01111,
        B01111,
        B01111,
        B01111,
        B00111
};
byte bar3[8] =
{
        B11111,
        B11111,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111
};
byte bar4[8] =
{
        B11110,
        B11100,
        B00000,
        B00000,
        B00000,
        B00000,
        B11000,
        B11100
};
byte bar5[8] =
{
        B01111,
        B00111,
        B00000,
        B00000,
        B00000,
        B00000,
        B00011,
        B00111
};
byte bar6[8] =
{
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111
};
byte bar7[8] =
{
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00111,
        B01111
};
byte bar8[8] =
{
        B11111,
        B11111,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000
};



void setup()
{
  // assignes each segment a write number
  lcd.createChar(1,bar1);
  lcd.createChar(2,bar2);
  lcd.createChar(3,bar3);
  lcd.createChar(4,bar4);
  lcd.createChar(5,bar5);
  lcd.createChar(6,bar6);
  lcd.createChar(7,bar7);
  lcd.createChar(8,bar8);
  state=1;
  state1=1;
  state2=1;
  // sets the LCD's rows and colums:
  lcd.begin(16, 2);
  pinMode(8,INPUT);
    pinMode(9,INPUT);
      pinMode(10,INPUT);
  s=0;
  m=0;
   h=0;
a=0;
}

void custom0(int col)
{ // uses segments to build the number 0
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(8); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(1);
}

void custom1(int col)
{
  lcd.setCursor(col,0);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
  lcd.setCursor(col,1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom2(int col)
{
  lcd.setCursor(col,0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(6);
}

void custom3(int col)
{
  lcd.setCursor(col,0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1); 
}

void custom4(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom5(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1);
}

void custom6(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
}

void custom7(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(8);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom8(int col)
{
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(1);
}

void custom9(int col)
{
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(7);  
  lcd.write(6);  
  lcd.write(1);
}

void printNumber(int value, int col) {
  if (value == 0) {
    custom0(col);
  } if (value == 1) {
    custom1(col);
  } if (value == 2) {
    custom2(col);
  } if (value == 3) {
    custom3(col);
  } if (value == 4) {
    custom4(col);
  } if (value == 5) {
    custom5(col);
  } if (value == 6) {
    custom6(col);
  } if (value == 7) {
    custom7(col);
  } if (value == 8) {
    custom8(col);
  } if (value == 9) {
    custom9(col);
  }      
}  


  
 
 
  
 




void loop()

{
  if(digitalRead(8)&&state==1){
    cnt++;
    state=0;
    if(cnt>3){
      cnt=0;
      }
    }else if(!digitalRead(8)&&state==0){
    state=1;
    }

if(digitalRead(9)&&state1==1){
    dg=1;
    state1=0;
     
    }else if(!digitalRead(9)&&state1==0){
    state1=1;
    }

if(digitalRead(10)&&state2==1){
     dg=-1;
     state2=0;
    }else if(!digitalRead(10)&state2==0){
    state2=1;
    }
    switch(cnt){
      case 1:
      m=m+dg;
      dg=0;  if(m>59){
    m=59;}
    if(m<0){
    m=0;}
      break;
     
      case 2:
      h=h+dg;
      dg=0;
      if(h>12){
    h=12;}
    if(h<0){
    h=1;}
      break;
          case 3:
     if(dg==1){
    a=1;
    dg=0;}
     if(dg==-1){
    a=0;
    dg=0;}
      break;
      }
  if(s>59){
    s=0;
    m++;
  
  if(m>59){
    m=0;
   h++;
  
  if(h>12){
    h=1;
    a=!a;
  } 
  }
  }
  d=h%10;
  printNumber(d, 3);
  d=h/10;
   printNumber(d, 0);

       d=m%10;
     printNumber(d, 10);
     d=m/10;
     printNumber(d, 7);
     lcd.setCursor(14, 0);
     if(a){
       lcd.print("AM");
      }else{
         lcd.print("PM");
        }
        if(cnt==0){
           s++;
          lcd.setCursor(6, 0);
      lcd.print(" ");
       lcd.setCursor(6, 1);
      lcd.print(" ");
      delay(500);
    lcd.setCursor(6, 0);
      lcd.print(".");
       lcd.setCursor(6, 1);
      lcd.print(".");
      
      delay(500);
       }
      
   
   


}  
