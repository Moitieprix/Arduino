int pinLed1, pinLed2;

void setup()
{
  pinLed1 = 2;
  pinLed2 = 3;
  
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
 
}


void loop()
{
    
    digitalWrite(pinLed2,HIGH);
    digitalWrite(pinLed1,HIGH);
    delay(1000);
    
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed1, LOW);
    delay(100);
  }


