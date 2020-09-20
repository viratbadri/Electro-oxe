#include <LiquidCrystal.h>   //include LCD library (standard library)
#include <Keypad.h>         
#define redLED 10 //define the LED pins
#define greenLED 11

char* password ="2451"; //create a password
int  keypos = 0;       //keypad position
int key_count=0;       // key count

const byte rows = 4; //number of the keypad's rows and columns
const byte cols = 4;

char keyMap [rows] [cols] = { //define the cymbols on the buttons of the keypad

  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins [rows] = {2, 3, 4, 5}; //pins of the keypad
byte colPins [cols] = {6, 7, 8, 9};

Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, rows, cols);

LiquidCrystal lcd (A0, A1, A2, A3, A4, A5); // pins of the LCD. (RS, E, D4, D5, D6, D7)

void setup(){

  lcd.begin(16, 2);
  pinMode(redLED, OUTPUT);  //set the LED as an output
  pinMode(greenLED, OUTPUT);
  setLocked (true); //state of the password
}

void loop(){
  setLocked (true);
  lcd.setCursor(0, 0);
  lcd.print("    Welcome");
  lcd.setCursor(0, 1);
  lcd.print(" Enter Password");
  char whichKey = myKeypad.getKey() ; //define which key is pressed with getKey
if(whichKey!=NO_KEY){
  key_count++;
  if(whichKey == '*' || whichKey == '#' || whichKey == 'A' ||       //define invalid keys
  whichKey == 'B' || whichKey == 'C' || whichKey == 'D'){
    keypos=0;
    setLocked (true);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Invalid Key!");
    delay(1000);
    lcd.clear();
  }
  if(whichKey == password [keypos]){

   keypos ++;
  }
 if(keypos == 4 && key_count == 4){
    setLocked (false);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*** Verified ***");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Welcome To   ");
    lcd.setCursor(0, 1);
    lcd.print("   Electro Oxe ");
    delay(7000);
    lcd.clear();
  }
  else if(key_count == 4 && keypos != 4){
  lcd.setCursor(0,1);
  lcd.print("WRONG PASSWORD") ;
  keypos = 0;  
  key_count=0;
  delay(500);}
}
}

void setLocked(int locked){
  if(locked){
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    }
    else{
      keypos = 0;  
      key_count=0;
      locked= true;
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
      
    }
  }
