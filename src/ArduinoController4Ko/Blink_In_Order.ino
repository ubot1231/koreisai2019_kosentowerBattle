
void Blink_In_Order(){
  
  analogWrite(TAPE1_LED,Tape1Value);
  analogWrite(TAPE2_LED,Tape2Value);
  analogWrite(TAPE3_LED,Tape3Value);
  
  Tape1Value += blinkSpeed_Tape1;

  if(Tape1Value >= 254){
    isTape1 = true;
    blinkSpeed_Tape1 = 0;
  }
  
  if(isTape1){ Tape2Value += blinkSpeed_Tape2; }
  
  if(Tape2Value >= 254){
    isTape2 = true;
    blinkSpeed_Tape2 = 0;
  }
  
  if(isTape2){ Tape3Value += blinkSpeed_Tape3; }

  if(!isTape3){
    if(Tape3Value >= 254){
      blinkSpeed_Tape3 = 0;
      isTape3 = true;
    }
  }
  
  if(isTape3){
    isTape1 = false;
    isTape2 = false;
    Tape1Value = 0;
    Tape2Value = 0;
    blinkSpeed_Tape1 = 0.05;
    blinkSpeed_Tape2 = 0.05;
   
    blinkSpeed_Tape3 = 0.05;
    Tape3Value = 0;
    isTape3 = false;
  }
  
}

