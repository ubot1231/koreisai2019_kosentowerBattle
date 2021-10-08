#include "Keyboard.h"

#define SWITCH_STATE 12
#define TAPE1_LED 13
#define TAPE2_LED 11
#define TAPE3_LED 10

const int LED_pin[4] = {9,6,5,3};
const int STATE_pin[4] = {8,7,4,2};

char serialChar = 0;

bool player1;
bool KTB_player1;
bool isPushed;
bool isState;

double Tape1Value;
double blinkSpeed_Tape1;
double Tape2Value;
double blinkSpeed_Tape2;
double Tape3Value;
double blinkSpeed_Tape3;

static bool isTape1;
static bool isTape2;
static bool isTape3;

void setup() {
  Keyboard.begin();
  Serial.begin(9600);
  
  pinMode(SWITCH_STATE, INPUT_PULLUP);

  for(const auto& state : STATE_pin){
    pinMode(state, INPUT_PULLUP);
  }

  for(const auto& led : LED_pin){
    pinMode(led, OUTPUT);
  }
  
  pinMode(TAPE1_LED, OUTPUT);
  pinMode(TAPE2_LED, OUTPUT);
  pinMode(TAPE3_LED, OUTPUT);
  
  player1 = true;
  isState = false;
  Tape1Value = 0;
  blinkSpeed_Tape1 = 0.05;
  Tape2Value = 0;
  blinkSpeed_Tape2 = 0.05;
  Tape3Value = 0;
  blinkSpeed_Tape3 = 0.05;

  isTape1 = false;
  isTape2 = false;
  isTape3 = false;
  
}

void loop() {

  serialChar = Serial.read();
  
  if(serialChar == '1'){
    KTB_player1 = true;
    //Serial.println(serialChar);
    }
  if(serialChar == '2'){
    KTB_player1 = false;
    //Serial.println(serialChar);
    }
  
  if((player1 == KTB_player1) || !player1 == !KTB_player1){
    ControllAsignment();
  
    if(buttonState() == false){
      for(const auto& led : LED_pin){ digitalWrite(led,HIGH); }
    }
    if(buttonState() == true){
      for(const auto& led : LED_pin){ digitalWrite(led,LOW); }
    }
    
    Blink_In_Order_Cyclically();
    //Blink_In_Order();

  }else{
    isState = false;
    
    Tape1Value = 0;
    Tape2Value = 0;
    Tape3Value = 0;

    analogWrite(TAPE1_LED,Tape1Value);
    analogWrite(TAPE2_LED,Tape2Value);
    analogWrite(TAPE3_LED,Tape3Value);
    
    isTape1 = false;
    isTape2 = false;
    isTape3 = false;
    
    for(const auto& led : LED_pin){ digitalWrite(led,LOW); }
  }

  //切り替え用
  if(digitalRead(SWITCH_STATE) == HIGH){
    if(isPushed){
      player1 = !player1;
      isPushed = false;
    }
  }
  
  if(digitalRead(SWITCH_STATE) == LOW){ isPushed = true; }
  
}//loopEnd

bool buttonState(){
  
  for(const auto& state : STATE_pin){
    if(digitalRead(state) == LOW){ return true; }
}
  return false;
}

