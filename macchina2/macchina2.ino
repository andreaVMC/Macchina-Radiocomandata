#include <avr/wdt.h>

int motoriSx = 9; // definisci il pin a cui è collegato il led
int motoriDx = 10;



void setup() {
  Serial.begin(9600); // inizializza la comunicazione seriale a 9600 bps
  pinMode(motoriSx, OUTPUT); // imposta il pin del led come uscita
  pinMode(motoriDx, OUTPUT);


  wdt_enable(WDTO_1S);
}

void loop() {
  wdt_reset();
  if (Serial.available() > 0) { // se ci sono dati disponibili sulla seriale
    char incomingByte = Serial.read(); // leggi un carattere dalla seriale
    if (incomingByte == '2') { // se il carattere ricevuto è '1'
      digitalWrite(motoriSx, HIGH); // accendi il led
      digitalWrite(motoriDx,HIGH);
      delay(200);
      wdt_reset();
      digitalWrite(motoriSx, LOW); // accendi il led
      digitalWrite(motoriDx, LOW); 
    } else if (incomingByte == '1') { // se il carattere ricevuto è '0'
      digitalWrite(motoriSx, LOW); // spegni il led
      digitalWrite(motoriDx, LOW); 
      wdt_reset();
    } else if(incomingByte == '3'){
      wdt_reset();
    }else if(incomingByte == '4'){
      wdt_reset();
    }
     else if(incomingByte == '5'){
      digitalWrite(motoriSx, HIGH); // accendi il led
      digitalWrite(motoriDx, HIGH); 
      delay(400);
      wdt_reset();
      digitalWrite(motoriSx, LOW); // spegni il led
      digitalWrite(motoriDx, LOW); 
    }else if(incomingByte == '6'){
      digitalWrite(motoriSx, HIGH); // accendi il led
      digitalWrite(motoriDx, ); 
      delay(400);
      wdt_reset();
      digitalWrite(motoriSx, LOW); // spegni il led
      digitalWrite(motoriDx, LOW); 
    }else{
      digitalWrite(motorSx, LOW); // spegni il led
      digitalWrite(motoriDx, LOW); 
      wdt_reset();
    }
  }
  while(Serial.available()>0){
    wdt_reset();
    char incomingByte = Serial.read();
  }
}