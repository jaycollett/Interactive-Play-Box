#include <Keypad.h>


const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {12, 7, 8, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {11, 13, 9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

const int redButton = 2;
const int redTrans =  3;  

const int grnButton = 4;
const int grnTrans = 5;

const int bluButton = A4;
const int bluTrans = 6;

const int yelButton = A5;

// music control pins, low signal plays music
const int musicPin1 = A1;
const int musicPin2 = A2;
const int musicPin3 = A3;

int keyPresses = 0;


void setup() {
  
  Serial.begin(9600);
  
  pinMode(musicPin1, OUTPUT);
  pinMode(musicPin2, OUTPUT);
  pinMode(musicPin3, OUTPUT);
  
  analogWrite(musicPin1, 100);
  analogWrite(musicPin2, 100);
  analogWrite(musicPin3, 100);
  
  pinMode(redTrans, OUTPUT);
  pinMode(grnTrans, OUTPUT);
  pinMode(bluTrans, OUTPUT);
  
  digitalWrite(redTrans, LOW);
  digitalWrite(grnTrans, LOW);
  digitalWrite(bluTrans, LOW);
  
  pinMode(redButton, INPUT);
  pinMode(grnButton, INPUT);
  pinMode(bluButton, INPUT);
  pinMode(yelButton, INPUT);
  
  digitalWrite(redButton, HIGH);
  digitalWrite(grnButton, HIGH);
  digitalWrite(bluButton, HIGH);
  digitalWrite(yelButton, HIGH);
   
}

void loop(){

  char key = keypad.getKey();
  
  if (key){
   switch(key){
   case '1':
     playBubblesSound();
     blinkLeds(bluTrans, 50, 4);
     break;
   case '3':
     playBubblesSound();
     blinkLeds(bluTrans, 50, 4);
     break;
   case '8':
     playWhishampSound();
     blinkLeds(bluTrans, 50, 4);
     break;
   default:
     randomLEDBlink();
   }
  }
  
  if(digitalRead(redButton) == LOW){
    digitalWrite(redTrans, HIGH); 
  }else{
    digitalWrite(redTrans, LOW);
  }
  
  if(digitalRead(grnButton) == LOW){
    digitalWrite(grnTrans, HIGH); 
  }else{
    digitalWrite(grnTrans, LOW);
  }
  
  if(digitalRead(bluButton) == LOW){
    digitalWrite(bluTrans, HIGH); 
  }else{
    digitalWrite(bluTrans, LOW);
  }
  
  if(digitalRead(yelButton) == LOW){
    digitalWrite(redTrans, HIGH);
    digitalWrite(grnTrans, HIGH); 
  }else{
    if(digitalRead(redButton) == HIGH){
      digitalWrite(redTrans, LOW);
    }
    if(digitalRead(grnButton) == HIGH){
      digitalWrite(grnTrans, LOW);
    }
  }
}


void playBubblesSound(){
  digitalWrite(musicPin2, LOW);
  delay(25);
  digitalWrite(musicPin2, HIGH);
}

void playDancingSound(){
  digitalWrite(musicPin1, LOW);
  delay(25);
  digitalWrite(musicPin1, HIGH);
}

void playWhishampSound(){
  digitalWrite(musicPin3, LOW);
  delay(25);
  digitalWrite(musicPin3, HIGH);
}


void blinkLeds(int ledPin, int blinkDelay, int blinkTimes){
 for(int i = 1;i<=blinkTimes;i++){
   Serial.println("...blink...");
   digitalWrite(ledPin, HIGH);
   delay(blinkDelay);
   digitalWrite(ledPin, LOW);
   delay(blinkDelay);
 }
}

void blinkYellowLeds(int blinkDelay, int blinkTimes){
 for(int i = 1;i<=blinkTimes;i++){
   Serial.println("...blink...");
   digitalWrite(redTrans, HIGH);
   digitalWrite(grnTrans, HIGH);
   delay(blinkDelay);
   digitalWrite(redTrans, LOW);
   digitalWrite(grnTrans, LOW);
   delay(blinkDelay);
 }
}

void randomLEDBlink(){
  randomSeed(millis());
  int blinkPattern = random(1,10);
  
  switch(blinkPattern){
    case 0:
      blinkLeds(bluTrans, 25, 2);
      blinkLeds(redTrans, 25, 3);
      blinkLeds(grnTrans, 25, 2);
      break;
    case 1:
      playDancingSound();
      blinkLeds(grnTrans, 49, 2);
      blinkLeds(redTrans, 10, 10);
      blinkLeds(grnTrans, 25, 2);   
      break;
    case 2:
      blinkLeds(bluTrans, 100, 5);
      blinkLeds(grnTrans, 25, 4);
      blinkLeds(redTrans, 50, 3);
      break;
    case 3:
      blinkLeds(redTrans, 125, 2);
      blinkLeds(bluTrans, 75, 3);
      break;
    case 4:
      blinkLeds(bluTrans, 25, 2);
      blinkLeds(redTrans, 25, 3);
      blinkLeds(grnTrans, 25, 2);
      break;
    case 5:
      playDancingSound();
      blinkYellowLeds(75, 2);
      blinkLeds(redTrans, 25, 3);
      break;
    case 6:
      blinkLeds(bluTrans, 25, 2);
      blinkYellowLeds(50, 3);
      break;
    case 7:
      blinkLeds(redTrans, 10, 10);
      blinkLeds(redTrans, 25, 3);
      blinkLeds(grnTrans, 50, 2);
      break;
    case 8:
      blinkYellowLeds(75, 3);
      break;
    case 9:
      blinkLeds(grnTrans, 25, 31);
      break;
    case 10:
      blinkLeds(redTrans, 25, 12);
      break;
  }
}
