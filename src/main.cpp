#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;
float temperature;

void setup(){
  Serial.begin(9600);
  Serial.println("Program Started");

    Wire.begin();
      Serial.println("I2C Started");

    if (bmp.begin(0x76))
    {
     Serial.println("BMP280 Found at 0x76");
    }
      else if (bmp.begin(0x77))
    {
      Serial.println("BMP280 Found at 0x77");
    }
    else
    {
      Serial.println("BMP280 Not Found");
    }
}

void loop(){
  float temperature = bmp.readTemperature();
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
      delay(1000);

}
