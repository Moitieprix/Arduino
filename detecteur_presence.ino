#include "Ultrasonic.h"
#include <Wire.h>
#include "rgb_lcd.h"

const long R0 = 100000; 
long Distance;
int pinLed1, pinLed2, a, B, pinTempSensor, pinLed3, pinLed4, pinLed5;

Ultrasonic ultrasonic(5);
rgb_lcd lcd;

void setup(){
  
  Serial.begin(9600);
  
  pinLed1 = 2;
  pinLed2 = 3;
  pinLed3 = 6;
  pinLed4 = 7;
  pinLed5 = 8;
  B = 4275;
  pinTempSensor = A0;

  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinLed5, OUTPUT);
  
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  digitalWrite(pinLed4, LOW);
  digitalWrite(pinLed5, LOW);

  lcd.begin(16, 2);

}
  
void loop(){

  Distance = ultrasonic.MeasureInCentimeters();
  delay(250);

    if (Distance < 40){
      affichageproche();
      }
    else if (Distance > 40){
       affichage();
      }
    }

void affichage(){
      a = analogRead(pinTempSensor);

    float R = 1023.0/a-1.0;
    R = R0*R;

    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;

      lcd.clear();
      lcd.setRGB(255, 255, 255);
      lcd.print("   Les Petits");
      lcd.setCursor(0, 1);
      lcd.print("     Princes");
    

    delay(5000);
    lcd.clear();

   lcd.setCursor(0, 0);
   lcd.print("Temperature :");
   lcd.setCursor(0, 1);
   lcd.print(temperature);
   lcd.print(" degres");
   

     delay(1500);
     lcd.clear();
    }

void affichageproche(){
      int i = 0;
  
      lcd.clear();
      lcd.setRGB(255, 255, 0);
      lcd.print("   Bienvenue");
      lcd.setCursor(0, 1);
      lcd.print("sur notre stand!");

      while(i < 2){
        digitalWrite(pinLed3, HIGH);
        digitalWrite(pinLed4, HIGH);
        digitalWrite(pinLed5, HIGH);
        delay(500);
        digitalWrite(pinLed3, LOW);
        digitalWrite(pinLed4, LOW);
        digitalWrite(pinLed5, LOW);
        delay(500);

        i++;
      }
}
