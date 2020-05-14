#include <PushButton.h>

#define GameRead 13

#define pinA 6 //CENTRAL HORIZONTAL
#define pinB 7 //LATERAL ESQUERDO VERTICAL DE CIMA
#define pinC 8 //DE CIMA HORIZONTAL
#define pinD 9 // LATERAL DIREITO VERTICAL DE CIMA
#define pinE 11 // DE BAIXO HORIZONTAL
#define pinF 12 // LATERAL DIREITO VERTICAL DE BAIXO
#define pinG 10 //LATERAL ESQUERDO VERTICAL DE BAIXO

#define pinbtnPlus 4
#define pinbtnMinum 5

#define led 2

#define buzzer 3

PushButton btnPlus(pinbtnPlus);
PushButton btnStart(pinbtnMinum);

void displayNumbers(int num);

int trying = 0;
int trysNumber = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);

  pinMode(led, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(GameRead, INPUT_PULLUP);

  digitalWrite(led, HIGH);

  Serial.begin(9600);

  //teste
}

void loop() {
  // put your main code here, to run repeatedly:
  btnPlus.button_loop();
  btnStart.button_loop();

  trying = digitalRead(GameRead);
  Serial.println(trying);

  if(btnPlus.pressed()){
    trysNumber++;  
  }

  displayNumbers(trysNumber); 

  if(btnStart.pressed()){
    while(true){
      trying = digitalRead(GameRead);
      Serial.println(trying);
      if(trying == 0){
        tone(buzzer, 400, 300);
        trysNumber--;
        displayNumbers(trysNumber);
        if(trysNumber == 0){
          tone(buzzer, 800, 10000);
          delay(10000);
          break;
        }
        delay(500);
      }
    }
  }

}

void displayNumbers(int num){
  switch(num){
    case 0:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
        
    case 1:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
        break;

    case 2:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;

    case 3:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);  
      break;

    case 4:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;

    case 5:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;

    case 6:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 7:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;

    case 8:
       digitalWrite(pinA, HIGH);
       digitalWrite(pinB, HIGH);
       digitalWrite(pinC, HIGH);
       digitalWrite(pinD, HIGH);
       digitalWrite(pinE, HIGH);
       digitalWrite(pinF, HIGH);
       digitalWrite(pinG, HIGH);
       break;

    case 9:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;
   }
}
