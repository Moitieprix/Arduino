#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698


// déclaration
int pinLed1, pinLed2, pinLed3, MusiquePin;  //variables des pins

int PrincesseDesNeigesRytm[] = {
  250,250,1500,250,250, 750,
  250,250,750,250,750,250, 750,
  250,250,1500,250,250,250, 250,
      750, 250,250,750,750,500,500,750, 0
};

int PrincesseDesNeigesNote[] = {
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_G4, NOTE_G4, NOTE_D5,
  NOTE_A4,  NOTE_A4, NOTE_A4,  NOTE_A4, NOTE_A4, NOTE_B4,
       NOTE_C5, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_G4, NOTE_G4, 
       NOTE_E5,NOTE_E5,NOTE_D5,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_E5,
    NOTE_F5,NOTE_E5,NOTE_C5,0
};


void setup()
{
  //initialisation des variables
  pinLed1 = 2;
  pinLed2 = 3;
  MusiquePin = 5;
  
  
  //initialisation des modes
  
  pinMode(6, OUTPUT);
  pinMode(6, INPUT);
  
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  
 
  //mise à 0V de chaque pin
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
 
}


void loop()
{
  
    //allumage des trois LED durant 1 seconde
    
    digitalWrite(pinLed2,HIGH);
    digitalWrite(pinLed1,HIGH);
    delay(1000);
    //on les éteint toutes brièvement
    
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed1, LOW);
    delay(100);
  //Boucle de la variable temps qui diminue
  for (int temps = 1000; temps >= 200; temps -= 200)
  {
    //les trois LEDs sont éteintes
    digitalWrite(pinLed1, HIGH);//allumage LED 3
    delay(temps); // pendant la valeur de temps
    digitalWrite(pinLed1,LOW); //on éteint la 3
    delay(100); // court délai, tout est éteint
    digitalWrite(pinLed2, HIGH);//allumage LED 2
    delay(temps); // pendant la valeur de temps
    digitalWrite(pinLed2,LOW); //on éteint la 2
    delay(100);
    
  }
  //retour au début de la loop();

  int i = 0;
      // Lecture du tableau de note ... lorsque nous lisons un 0  c'est que c'est la fin
  while (PrincesseDesNeigesNote[i] != 0){
      //On joue la note
    tone(MusiquePin, PrincesseDesNeigesNote[i],PrincesseDesNeigesRytm[i]);
          //On attend X millisecondes (durée de la note) avant de passer à la suivante
    delay(PrincesseDesNeigesRytm[i]);
      //On arrête la lecture de la note
    noTone(MusiquePin);
      //On marque une courte pose (entre chaque note, pour les différencer)
    delay(50);
      //On passe à la note suivante
    ++i;
  }
}


