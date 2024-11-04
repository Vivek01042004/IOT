#include"DHT.h"

#define DHTTYPE DHT11
#define dht_dpin 14

DHT dht(dht_dpin,DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
   dht.begin();
 pinMode(dht_dpin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int h=dht.readHumidity();
  unsigned int t=dht.readTemperature();
  Serial.println("humidity=");
  Serial.print(h);
  Serial.println("Temp=");
  Serial.print(t);

}
