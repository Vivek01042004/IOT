/* Fill-in your Template ID Device Name and Auth Token */
#define BLYNK_TEMPLATE_ID "TMPL3XzRCWyrg"
#define BLYNK_TEMPLATE_NAME "4 LEDs"
#define BLYNK_AUTH_TOKEN "FEjCHq4RrhOJDry_ezVgqCS1pk7UideM"
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Huh";
char pass[] = "12345678";
//#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Preferences.h>
Preferences pref;
// define the GPIO connected with  Relays and switches
#define led1 25
#define led2 26
#define led3 32 
#define led4 33 



#define wifiLed   2   //D2

//Change the virtual pins according yours
#define VPIN_BUTTON_1    V0
#define VPIN_BUTTON_2    V1
#define VPIN_BUTTON_3    V2
#define VPIN_BUTTON_4    V3


int wifiFlag = 0;
char auth[] = BLYNK_AUTH_TOKEN;
BlynkTimer timer;
// When App button is pushed - switch the state

BLYNK_WRITE(V0)
{
  int s1 = param.asInt(); // parameter as int 
  if(s1 == HIGH)
  {    
  digitalWrite(25,LOW);
  digitalWrite(26,HIGH);
  digitalWrite(32,HIGH);
  digitalWrite(33,LOW);
 
    }  
  else
  {
  digitalWrite(25,LOW);
  digitalWrite(26,LOW);
  digitalWrite(32,LOW);
  digitalWrite(33,LOW);
  }  
}
BLYNK_WRITE(V1)
{
  int s2 = param.asInt(); // parameter as int 
  if(s2 == HIGH)
  {    
  digitalWrite(25,HIGH);
  digitalWrite(26,LOW);
  digitalWrite(32,LOW);
  digitalWrite(33,HIGH);
  }  
  else
  {
  digitalWrite(25,LOW);
  digitalWrite(26,LOW);
  digitalWrite(32,LOW);
  digitalWrite(33,LOW);
  }  
}
BLYNK_WRITE(V2)
{
  int s3 = param.asInt(); // parameter as int 
  if(s3 == HIGH)
  {    
  digitalWrite(25,LOW);
  digitalWrite(26,HIGH);
  digitalWrite(32,LOW);
  digitalWrite(33,LOW);
  }  
  else
  {
  digitalWrite(25,LOW);
  digitalWrite(26,LOW);
  digitalWrite(32,LOW);
  digitalWrite(33,LOW);
  }  
}
BLYNK_WRITE(V3)
{
  int s4 = param.asInt(); // parameter as int 
  if(s4 == HIGH)
  {    
  digitalWrite(25,LOW);
  digitalWrite(26,LOW);
  digitalWrite(32,HIGH);
  digitalWrite(33,LOW);} 
    else{
    digitalWrite(25,LOW);
  digitalWrite(26,LOW);
  digitalWrite(32,LOW);
  digitalWrite(33,LOW);}
} 
void checkBlynkStatus() { // called every 3 seconds by SimpleTimer
  bool isconnected =  Blynk.connected();
  if (isconnected == false) {
    wifiFlag = 1;
    digitalWrite(wifiLed, LOW);
    Serial.println(" Blynk Not Connected");
  }
  if (isconnected == true) {
    wifiFlag = 0;
    digitalWrite(wifiLed, HIGH);
    Serial.println("Blynk Connected");
  }
}
BLYNK_CONNECTED() {
  // update the latest state to the server
  Blynk.virtualWrite(VPIN_BUTTON_1, 0);
  Blynk.virtualWrite(VPIN_BUTTON_2, 0);
  Blynk.virtualWrite(VPIN_BUTTON_3, 0);
  Blynk.virtualWrite(VPIN_BUTTON_4, 0);

}


void setup()
{
  Serial.begin(115200);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  analogWrite(2, 255);
  analogWrite(4, 255);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(wifiLed, OUTPUT);
 


  //During Starting all  Relays should TURN OFF
  digitalWrite(led1, 0);
  digitalWrite(led2, 0);
  digitalWrite(led3, 0);
  digitalWrite(led4, 0);
  digitalWrite(wifiLed, LOW);   
  WiFi.begin(ssid, pass);
  timer.setInterval(2000L, checkBlynkStatus); // check if  Blynk server is connected every 2 seconds

  Blynk.config(auth);
  delay(1000);
  
}
void loop()
{
  Blynk.run();
  timer.run(); // Initiates SimpleTimer
}