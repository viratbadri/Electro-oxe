#include <LedControl.h>
int DIN = 10;
int CS =  9;
int CLK = 8;

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       
 lc.setIntensity(0,15);      //Adjust the brightness maximum is 15
 lc.clearDisplay(0);    
}

void loop(){ 
    
    //Facial Expression
   
    byte facebook_on[] ={0xff, 0x81, 0x89, 0xff, 0x8b, 0x89, 0x81, 0xff}; //facebook led out

    byte smile[] ={0x3c, 0x42, 0x95, 0xa1, 0xa1, 0x95, 0x42, 0x3c};      //smile

    byte gmail[] ={0xff, 0x06, 0x0c, 0x18, 0x18, 0x0c, 0x06, 0xff};        // gmail

    byte nike [] ={ 0x10, 0x30, 0x60, 0x60, 0x30, 0x18, 0x0c, 0x06};    //nike
    
    byte google []={0x3c, 0x42, 0x81, 0x81, 0xb1, 0x91, 0x52, 0x34};
    
    byte ele[]={0x7e, 0x81, 0x99, 0xa5, 0xd3, 0x89, 0xa5, 0x7e};

    byte ballsm[]={0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00};
    
    byte sprite1[]={0x98, 0x5c, 0xb6, 0x5f, 0x5f, 0xb6, 0x5c, 0x98};

    byte sprite2[]={0x58, 0xbc, 0x16, 0x3f, 0x3f, 0x16, 0xbc, 0x58};

    byte sprite3[]={0xb8, 0x74, 0x3f, 0x3e, 0x3e, 0x3f, 0x74, 0xb8};

    byte sprite4[]={0x58, 0xbc, 0x16, 0x3f, 0x3f, 0x16, 0xbc, 0x58};
    
    byte balllar[]={0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff};

    
    //circle
    
    byte s1[]={0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00};
    byte s2[]={0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00};
    byte s3[]={0x00, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x00};
    byte s4[]={0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    byte x[] ={0x83, 0xc6, 0x64, 0x18, 0x18, 0x64, 0xc6, 0x83};  
    byte s5[]={0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff};
    byte s6[]={0xff, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xff};
    byte s7[]={0xff, 0xff, 0xff, 0xe7, 0xe7, 0xff, 0xff, 0xff};
    
    //arrow
    byte c1[] ={0x10, 0x18, 0x1c, 0xff, 0xff, 0x1c, 0x18, 0x10};
    byte c2[] ={0x08, 0x0c, 0x0e, 0x7f, 0x7f, 0x0e, 0x0c, 0x08};
    byte c3[] ={0x04, 0x06, 0x07, 0x3f, 0x3f, 0x07, 0x06, 0x04};
    byte c4[] ={0x02, 0x02, 0x03, 0x1f, 0x1f, 0x03, 0x02, 0x02};
    byte c5[] ={0x01, 0x01, 0x01, 0x0f, 0x0f, 0x01, 0x01, 0x01};
    byte c6[] ={0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00};
    byte c7[] ={0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00};
    byte c8[] ={0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00};
   
    byte d1[] ={0x08, 0x0c, 0x0e, 0x7f, 0x7f, 0x0e, 0x0c, 0x08};
    byte d2[] ={0x08, 0x0c, 0x0e, 0x7f, 0x7f, 0x0e, 0x0c, 0x08};
    byte d3[] ={0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00};
    byte d4[] ={0x00, 0x00, 0x80, 0xe0, 0xe0, 0x80, 0x00, 0x00};
    byte d5[] ={0x80, 0xc0, 0xe0, 0xf8, 0xf8, 0xe0, 0xc0, 0x80};
    byte d6[] ={0x40, 0x60, 0x70, 0xfc, 0xfc, 0x70, 0x60, 0x40};
    byte d7[] ={0x20, 0x30, 0x38, 0xfe, 0xfe, 0x38, 0x30, 0x20};
    byte d8[] ={0x10, 0x18, 0x1c, 0xff, 0xff, 0x1c, 0x18, 0x10};



    
    //face_book
    printByte(facebook_on);
    delay(2000);

    printByte(gmail);
    delay(2000);
    
    printByte(nike);
    delay(2000);
    
    printByte(google);
    delay(2000); 
    
    printByte(ele);
    delay(2500);

    for (int i=0;i<3;i++){
//Moving car
    printByte(d1);
    delay(50);
    printByte(d2);
    delay(50);
    printByte(d3);
    delay(50);
    printByte(d4);
    delay(50);
    printByte(d5);
    delay(50);
    printByte(d6);
    delay(50);
    printByte(d7);
    delay(50);
    printByte(d8);
    delay(50);
    printByte(c1);
    delay(50);
    printByte(c2);
    delay(50);
    printByte(c3);
    delay(50);
    printByte(c4);
    delay(50);
    printByte(c5);
    delay(50);
    printByte(c6);
    delay(50);
    printByte(c7);
    delay(50);
    printByte(c8);
    delay(50);}

   for (int i=0;i<7;i++){
//circle illusion
    printByte(s1);
    delay(50);
    printByte(s2);
    delay(50);
    printByte(s3);
    delay(50);
    printByte(s4);
    delay(50);
    printByte(s5);
    delay(50);
    printByte(s6);
    delay(50);
    printByte(s7);
    delay(50);
    }

    for (int i=0;i<4;i++){
    printByte(ballsm);
    delay(500);
    printByte(balllar);
    delay(500);
    }
     
    printByte(smile);
    delay(3000);

   for (int i=0;i<3;i++){
    printByte(sprite1);
    delay(2000);

    printByte(sprite2);
    delay(2000);
    
    printByte(sprite3);
    delay(2000);
    
    printByte(sprite4);
    delay(2000); 
   }
}
  
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}