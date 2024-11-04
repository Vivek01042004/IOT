// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Mouni";
char pass[] = "mounikashok";
//#define BLYNK_PRINT Serial
#include <WiFi.h>
//#include <WiFiClient.h>

#define wifiLed   2
void setup() {
  // put your setup code here, to run once:
  
       Serial.begin(9600);
       delay(10);
               
       Serial.println("Connecting to ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 
      Serial.println(WiFi.localIP() );
}
 


void loop() {
  // put your main code here, to run repeatedly:

}
