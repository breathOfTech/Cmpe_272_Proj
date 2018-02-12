#include <LiquidCrystal.h>

#include "DHT.h"

#define DHTPIN A0     

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(12, 11 , 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  delay(2000);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Welcome!");
  lcd.clear();
  dht.begin();
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

  lcd.print("Temperature: ");
  lcd.setCursor(0,1);
  lcd.print(t);
  lcd.setCursor(5,1);
  lcd.print(" *C ");


  delay(2000);
  lcd.clear();
}
