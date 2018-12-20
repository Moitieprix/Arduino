#include "Ultrasonic.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include <math.h>
  
  Ultrasonic ultrasonic(5);
  rgb_lcd lcd;
  
  
  const long R0 = 100000;   
  long Distance;
  int pinLed1, pinLed2, a, B, pinTempSensor, colorR, colorG, colorB;

void setup(){
  
  Serial.begin(9600);
  
  pinLed1 = 2;
  pinLed2 = 3;
  B = 4275;
  pinTempSensor = A0;
  colorR = 255;
  colorG = 255;
  colorB = 255;

  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);

  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
   

}
  
void loop(){
    affichage();
}

void affichage(){

  Distance = ultrasonic.MeasureInCentimeters();

   a = analogRead(pinTempSensor);

    float R = 1023.0/a-1.0;
    R = R0*R;

    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;

  lcd.setCursor(0, 0);
    lcd.print("Distance :");
   lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(Distance);
    lcd.print("cm ");
    

    delay(3000);
    lcd.clear();

   lcd.setCursor(0, 0);
    lcd.print("Temperature :");
   lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(temperature);
    lcd.print(" degres");
   

     delay(3000);
     lcd.clear();

}
  


