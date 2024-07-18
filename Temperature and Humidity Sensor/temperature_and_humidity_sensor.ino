#include "DHT.h"
#define DHTPIN 4     // Digital pin  #2 on ESP8266
#define DHTTYPE DHT22 // Sensor type 
DHT dht(DHTPIN, DHTTYPE);
float humidity,temperature_C,temperature_F ;
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
delay(2000);

temperature_C = dht.readTemperature();
  
temperature_F = dht.readTemperature(true);

humidity = dht.readHumidity();
  
 

  // Check for error reading
  if (isnan(humidity) || isnan(temperature_C) || isnan(temperature_F)) {
    Serial.println(" DHT reading failed ");
    return;
  }


  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  
  Serial.print("Temperature:");
  Serial.print(temperature_C);
  Serial.print(("°C ------- "));
  
  Serial.print(temperature_F);
  Serial.println("°F");
}#include "DHT.h"
#define DHTPIN 4     // Digital pin  #2 on ESP8266
#define DHTTYPE DHT22 // Sensor type 
DHT dht(DHTPIN, DHTTYPE);
float humidity,temperature_C,temperature_F ;
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
delay(2000);

temperature_C = dht.readTemperature();
  
temperature_F = dht.readTemperature(true);

humidity = dht.readHumidity();
  
 

  // Check for error reading
  if (isnan(humidity) || isnan(temperature_C) || isnan(temperature_F)) {
    Serial.println(" DHT reading failed ");
    return;
  }


  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  
  Serial.print("Temperature:");
  Serial.print(temperature_C);
  Serial.print(("°C ------- "));
  
  Serial.print(temperature_F);
  Serial.println("°F");
}
