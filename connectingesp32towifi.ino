char ssid[]="Huh";//Your wifi name
char pass[]="12345678";//Wifi password
#include <WiFi.h>//#include <WiFiClient.h>
#define wifiled  2
void setup() {
  pinMode(2,OUTPUT);
  digitalWrite(2, HIGH);
  Serial.begin(9600);
  delay(10);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  digitalWrite(2, HIGH);
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}
