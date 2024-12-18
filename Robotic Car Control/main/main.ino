#define ENA   14          // Enable/speed motors Right        GPIO14(D5)
#define ENB   12          // Enable/speed motors Left         GPIO12(D6)
#define IN_1  15          // L298N in1 motors Right           GPIO15(D8)
#define IN_2  13          // L298N in2 motors Right           GPIO13(D7)
#define IN_3  2           // L298N in3 motors Left            GPIO2(D4)
#define IN_4  0           // L298N in4 motors Left            GPIO0(D3)

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <Servo.h> // servo library  
Servo s1;
Servo s2;

String command;  
int a = 0;  
int b = 0;           //String to store app command state.
int speedCar = 800;         // 400 - 1023.
int speed_Coeff = 3;

const char* ssid = "Saurav Zanje";
ESP8266WebServer server(80);

void setup() {
 
 pinMode(ENA, OUTPUT);
 pinMode(ENB, OUTPUT);  
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT); 
  
  Serial.begin(115200);
  
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();  
     s1.attach(4);
     s2.attach(5);  
}

void goAhead(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
  }

void goBack(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
  }

void goRight(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
  }

void goLeft(){

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
  }

void goAheadRight(){
      
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar/speed_Coeff);
 
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
   }

void goAheadLeft(){
      
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar/speed_Coeff);
  }

void goBackRight(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar/speed_Coeff);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
  }

void goBackLeft(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar/speed_Coeff);
  }

void stopRobot(){  

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
 }

 void F1(){ 
  if ( a > 360 ) 
    a=360;
  s1.write(a);  
  delay(100);
  a++;
 }

 void F2(){  
  if ( a < 0 ) 
    a=0;
  s1.write(a);  
  delay(100);
  a--;
 }

 void F3(){  
  if ( b > 360 ) 
    b=360;
  s2.write(b);  
  delay(100);
  b++;
 }

 void F4(){  
  if ( b < 0 ) 
    b=0;
  s2.write(b);  
  delay(100);
  b--;
 }

void loop() {
    server.handleClient();
      command = server.arg("State");
      if (command == "F" && speedCar > 700 ) goAhead();
      else if (command == "B" && speedCar > 700) goBack();
      else if (command == "L" && speedCar > 700) goLeft();
      else if (command == "R" && speedCar > 700) goRight();
      else if (command == "I" && speedCar > 700) goAheadRight();
      else if (command == "G" && speedCar > 700) goAheadLeft();
      else if (command == "J" && speedCar > 700) goBackRight();
      else if (command == "H" && speedCar > 700) goBackLeft(); 
      else if (command == "F" && speedCar < 700) F1();
      else if (command == "B" && speedCar < 700) F2();
      else if (command == "L" && speedCar < 700) F3();
      else if (command == "R" && speedCar < 700) F4();
      else if (command == "0") speedCar = 400;
      else if (command == "1") speedCar = 470;
      else if (command == "8") speedCar = 960;
      else if (command == "9") speedCar = 1023;
      else if (command == "S") stopRobot();
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}