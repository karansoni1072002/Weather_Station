  
#include <LiquidCrystal.h> 
#include "DHT.h"

int Contrast=75;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
 #define DHTPIN 9  
 #define DHTTYPE DHT22 

 DHT dht(DHTPIN, DHTTYPE);

 void setup()
 {
    analogWrite(6,Contrast);
     lcd.begin(16, 2);
     
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
 } 
 void loop()
 {
     delay(2000);

     float h = dht.readHumidity();
     float t = dht.readTemperature();
     float f = dht.readTemperature(true);

     if (isnan(h) || isnan(t) || isnan(f)) 
     {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
     }

     float hif = dht.computeHeatIndex(f, h);
     float hic = dht.computeHeatIndex(t, h, false);
  
     lcd.setCursor(0, 0);
     lcd.print("TEMP = ");

     lcd.print(t);
     lcd.print("°C");
   
    lcd.setCursor(0, 1);
    lcd.print("HUMIDITY=");
 
    lcd.print(h);
    lcd.print("%");
 }
