#include<ESP8266WiFi.h>
#include <LiquidCrystal.h>
const int rs = 14, en = 12, d4 = 5, d5 = 4, d6 = 0, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const char* ssid = "White_devil";    //  Your Wi-Fi Name

const char* password = "viratbadri";   // Wi-Fi Password

  

WiFiServer server(80);

void setup()
{
  lcd.begin(16,2);
  Serial.begin(115200); //Default Baudrate
  Serial.print("Connecting to the Newtork");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)

  {

    delay(500);

    Serial.print(".");

  }

  Serial.println("WiFi connected"); 

  server.begin();  // Starts the Server

  Serial.println("Server started");

 

  Serial.print("IP Address of network: "); // will IP address on Serial Monitor

  Serial.println(WiFi.localIP());

  Serial.print("Copy and paste the following URL: https://"); // Will print IP address in URL format

  Serial.print(WiFi.localIP());

  Serial.println("/");

}

 

void loop()

{

  WiFiClient client = server.available();

  if (!client)

  {

    return;

  }

  Serial.println("Waiting for new client");

  while(!client.available())

  {

    delay(1);

  }

 

  String request = client.readStringUntil('\r');
  
  Serial.println("Request");
  Serial.println(request);
  request =  request.substring(request.indexOf(" ")+2,request.length());
//  Serial.println(request);
  request =  request.substring(0, request.indexOf(" "));
//  Serial.println(request);
  Serial.println(request.indexOf("favicon.ico"));
  if(request.indexOf("favicon.ico") == -1)
  {
      lcd.clear();
      lcd.print(request);     
  } 
 
  client.flush();


//*------------------HTML Page Code---------------------*//

 

client.println("<!DOCTYPE html>");
client.println("<html>");
client.println("<body> Name: <input type=\"text\" id=\"myText\" value=\"\">");
client.println("<button onclick=\"myFunction()\">Try it</button>");
client.println("<script> function myFunction() { val = document.getElementById(\"myText\").value; url = window.location.origin; newurl = url + '/' + val; console.log(val); window.location.href=newurl; }</script>");
client.println("</body>");
client.println("</html>");

  delay(1);

  Serial.println("Client disonnected");

  Serial.println("");

}
