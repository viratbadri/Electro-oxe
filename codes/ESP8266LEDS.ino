#include<ESP8266WiFi.h>

const char* ssid = "White_devil";    //  Your Wi-Fi Name

const char* password = "password";   // Wi-Fi Password

int LED1 = 2,LED2 = 0,BUZZER = 4;   

WiFiServer server(80);

void setup()
{

  Serial.begin(115200); //Default Baudrate

  pinMode(LED1, OUTPUT); 

  digitalWrite(LED1, LOW);
  pinMode(LED2, OUTPUT); 

  digitalWrite(LED2, LOW);
  pinMode(BUZZER, OUTPUT); 

  digitalWrite(BUZZER, LOW);
  
  
  

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

  client.flush();

//  Serial.println(request.indexOf("/LED=ON"));

  int value1 = LOW, value2 =LOW, value3=LOW;

  if(request.indexOf("LED1=ON") != -1)

  {

    digitalWrite(LED1, HIGH); // Turn LED ON

    Serial.println(request.indexOf("LED1=ON"));

    value1 = HIGH;

  }

  if(request.indexOf("LED1=OFF") != -1)

  {

    digitalWrite(LED1, LOW); // Turn LED OFF

    Serial.println(request.indexOf("/LED1=OFF"));

    value1 = LOW;

  }
   if(request.indexOf("LED2=ON") != -1)

  {

    digitalWrite(LED2, HIGH); // Turn LED ON

    Serial.println(request.indexOf("LED2=ON"));

    value2 = HIGH;

  }

  if(request.indexOf("LED2=OFF") != -1)

  {

    digitalWrite(LED2, LOW); // Turn LED OFF

    Serial.println(request.indexOf("/LED2=OFF"));

    value2 = LOW;

  }

 if(request.indexOf("BUZZER=ON") != -1)

  {

    digitalWrite(BUZZER, HIGH); // Turn LED ON

    Serial.println(request.indexOf("BUZZER=ON"));

    value3 = HIGH;

  }

  if(request.indexOf("BUZZER=OFF") != -1)

  {

    digitalWrite(BUZZER, LOW); // Turn LED OFF

    Serial.println(request.indexOf("/BUZZER=OFF"));

    value3 = LOW;
  }
//*------------------HTML Page Code---------------------*//

 

  client.println("HTTP/1.1 200 OK"); //

  client.println("Content-Type: text/html");

  client.println("");

  client.println("<!DOCTYPE HTML>");

  client.println("<html>");

 

  client.print(" CONTROL LED 1: ");

 

  if(value1 == HIGH)

  {

    client.print("ON");

  }

  else

  {

    client.print("OFF");

  }

  client.println("<br><br>");

  client.println("<a href=\"/LED1=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/LED1=OFF\"\"><button>OFF</button></a><br />");

  
  
  client.print(" CONTROL LED 2: ");

 

  if(value2 == HIGH)

  {

    client.print("ON");

  }

  else

  {

    client.print("OFF");

  }
client.println("<br><br>");
  
   client.println("<a href=\"/LED2=ON\"\"><button>ON</button></a>");
   client.println("<a href=\"/LED2=OFF\"\"><button>OFF</button></a><br />");

   client.print(" CONTROL BUZZER: ");

 

  if(value3 == HIGH)

  {

    client.print("ON");

  }

  else

  {

    client.print("OFF");

  }

  client.println("<br><br>");

  client.println("<a href=\"/BUZZER=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/BUZZER=OFF\"\"><button>OFF</button></a><br />");
   
   
   client.println("</html>");

 

  delay(1);

  Serial.println("Client disonnected");

  Serial.println("");

}
