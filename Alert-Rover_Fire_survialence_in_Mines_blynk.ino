/* Fill-in your Template ID Device Name and Auth Token */
#define BLYNK_TEMPLATE_ID "TMPL3BkNGRKNJ"
#define BLYNK_TEMPLATE_NAME "First"
#define BLYNK_AUTH_TOKEN "n0F_z_vLVoJG2b3IxUsTbAQZSCP_PXna"
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "prasanna";
char pass[] = "prassaaa";
//#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Preferences.h>
Preferences pref;
// define the GPIO connected with  Relays and switches
#define m11 25
#define m12 26
#define m21 32 
#define m22 33 

int Fire=5; //Set Analog Input 5 for Fire.
int Buzzer=27;


#define LEN   2   //Left pin Enable
#define REN   4  //Right pin Enable

//Change the virtual pins according yours
#define VPIN_BUTTON_1    V0
#define VPIN_BUTTON_2    V1
#define VPIN_BUTTON_3    V2
#define VPIN_BUTTON_4    V3
#define VPIN_FIRE_5    V6


int wifiFlag = 0;
char auth[] = BLYNK_AUTH_TOKEN;
BlynkTimer timer;
// When App button is pushed - switch the state
BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); // parameter as int 
  if(s0 == HIGH)
  {    
    digitalWrite(m11,HIGH);
    digitalWrite(m12,LOW);
    digitalWrite(m21,HIGH);
    digitalWrite(m22,LOW);
  Blynk.virtualWrite(VPIN_BUTTON_1, 1);
  Blynk.virtualWrite(VPIN_BUTTON_2, 0);
  Blynk.virtualWrite(VPIN_BUTTON_3, 0);
  Blynk.virtualWrite(VPIN_BUTTON_4, 0);
    delay(10);
    }  
  else
  {
    digitalWrite(m11,LOW);
    digitalWrite(m12,LOW);
    digitalWrite(m21,LOW);
    digitalWrite(m22,LOW);
     Blynk.virtualWrite(VPIN_BUTTON_1, 0);
     Blynk.virtualWrite(VPIN_BUTTON_2, 0);
     Blynk.virtualWrite(VPIN_BUTTON_3, 0);
     Blynk.virtualWrite(VPIN_BUTTON_4, 0);
    delay(10);
    }  
}
BLYNK_WRITE(V1)
{
  int s1 = param.asInt(); // parameter as int 
  if(s1 == HIGH)
  {    
    digitalWrite(m11,LOW);
    digitalWrite(m12,HIGH);
    digitalWrite(m21,LOW);
    digitalWrite(m22,HIGH);
     Blynk.virtualWrite(VPIN_BUTTON_1, 0);
     Blynk.virtualWrite(VPIN_BUTTON_2, 1);
     Blynk.virtualWrite(VPIN_BUTTON_3, 0);
     Blynk.virtualWrite(VPIN_BUTTON_4, 0);
    delay(10);
 
    }  
  else
  {
    digitalWrite(m11,LOW);
    digitalWrite(m12,LOW);
    digitalWrite(m21,LOW);
    digitalWrite(m22,LOW);
     Blynk.virtualWrite(VPIN_BUTTON_1, 0);
     Blynk.virtualWrite(VPIN_BUTTON_2, 0);
     Blynk.virtualWrite(VPIN_BUTTON_3, 0);
     Blynk.virtualWrite(VPIN_BUTTON_4, 0);
    delay(10);
    }  
}
BLYNK_WRITE(V2)
{
  int s2 = param.asInt(); // parameter as int 
  if(s2 == HIGH)
  {    
    digitalWrite(m11,LOW);
    digitalWrite(m12,LOW);
    digitalWrite(m21,HIGH);
    digitalWrite(m22,LOW);
    Blynk.virtualWrite(VPIN_BUTTON_1, 0);
     Blynk.virtualWrite(VPIN_BUTTON_2, 0);
     Blynk.virtualWrite(VPIN_BUTTON_3, 1);
     Blynk.virtualWrite(VPIN_BUTTON_4, 0);
    delay(10);
    }  
  else
  {
    digitalWrite(m11,LOW);
    digitalWrite(m12,LOW);
    digitalWrite(m21,LOW);
    digitalWrite(m22,LOW);
     Blynk.virtualWrite(VPIN_BUTTON_1, 0);
     Blynk.virtualWrite(VPIN_BUTTON_2, 0);
     Blynk.virtualWrite(VPIN_BUTTON_3, 0);
     Blynk.virtualWrite(VPIN_BUTTON_4, 0);
    delay(10);
    }  
}
BLYNK_WRITE(V3)
{
  int s3 = param.asInt(); // parameter as int 
  if(s3 == HIGH)
  {    
    digitalWrite(m11,HIGH);
    digitalWrite(m12,LOW);
    digitalWrite(m21,LOW);
    digitalWrite(m22,LOW);
   Blynk.virtualWrite(VPIN_BUTTON_1, 0);
   Blynk.virtualWrite(VPIN_BUTTON_2, 0);
   Blynk.virtualWrite(VPIN_BUTTON_3, 0);
   Blynk.virtualWrite(VPIN_BUTTON_4, 1);
    delay(10);
    }  
  else
  {
    digitalWrite(m11,LOW);
    digitalWrite(m12,LOW);
    digitalWrite(m21,LOW);
    digitalWrite(m22,LOW);
     Blynk.virtualWrite(VPIN_BUTTON_1, 0);
     Blynk.virtualWrite(VPIN_BUTTON_2, 0);
     Blynk.virtualWrite(VPIN_BUTTON_3, 0);
     Blynk.virtualWrite(VPIN_BUTTON_4, 0);
    delay(10);
    }  
}

void checkBlynkStatus() { // called every 3 seconds by SimpleTimer
  bool isconnected =  Blynk.connected();
  if (isconnected == false) {
    wifiFlag = 1;
   // digitalWrite(wifiLed, LOW);
    Serial.println(" Blynk Not Connected");
  }
  if (isconnected == true) {
    wifiFlag = 0;
    //digitalWrite(wifiLed, HIGH);
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


void getRelayState()
{
  //Serial.println("reading data from NVS");
 void forward();
 void left();
 void right();
 void back();
  delay(200);
}

void readSensor() {
int value=digitalRead(Fire);   //Reads the Value of Fire sensor.
Serial.print("Sensor value is :");   //Prints the value of Fire sensor to Serial Monitor.
Serial.println(value);
if(value==1)
  {
    digitalWrite(Buzzer,HIGH);//The LED turns ON in Dark.
    Serial.println("Fire Detected");

    // Trigger event if temperature exceeds 30°C
    Blynk.logEvent("FireAlert", String("Fire Detected ") + value + "Warning");
    // This event can now trigger an email or notification from the Blynk app
  }
  else
  {
    digitalWrite(Buzzer,LOW);//The LED turns OFF in Light.
    Serial.println("No Fire");
  }
  Blynk.virtualWrite(V6,value); // WRITING TEMPERATURE VALUE TO VIRTUAL PIN V5 IN BLYNK
  
  }


void setup()
{
  Serial.begin(115200);

  //Open namespace in read-write mode
  pref.begin("Relay_State", false);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(LEN,OUTPUT);
  pinMode(REN,OUTPUT);
  pinMode(Fire,INPUT);
  pinMode(Buzzer,OUTPUT);
  //pinMode(wifiLed, OUTPUT);
 


  //During Starting all  Relays should TURN OFF
  digitalWrite(m11, 0);
  digitalWrite(m12, 0);
  digitalWrite(m21, 0);
  digitalWrite(m22, 0);
  //digitalWrite(wifiLed, LOW);   // Enabling DHT sensor
  analogWrite(LEN,255);
  analogWrite(REN,255);
  WiFi.begin(ssid, pass);
 
  Blynk.config(auth);
  delay(1000);
  getRelayState(); //fetch data from NVS Flash Memory
  //  delay(1000);
}
void loop()
{
  readSensor();
  Blynk.run();
  timer.run(); // Initiates SimpleTimer
}

void forward()
{
   digitalWrite(m11,HIGH);
   digitalWrite(m12,LOW);
   digitalWrite(m21,HIGH);
   digitalWrite(m22,LOW);
   
}
void backward()
{
   digitalWrite(m11,LOW);
   digitalWrite(m12,HIGH);
   digitalWrite(m21,LOW);
   digitalWrite(m22,HIGH);
}
void left()
{
   digitalWrite(m11,HIGH);
   digitalWrite(m12,LOW);
   digitalWrite(m21,LOW);
   digitalWrite(m22,LOW);
}
void right()
{
   digitalWrite(m11,LOW);
   digitalWrite(m12,LOW);
   digitalWrite(m21,HIGH);
   digitalWrite(m22,LOW);
}
void halt()
{
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
}