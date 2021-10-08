
bool isTape1Down = false;
bool isTape2Down = false;
bool isTape3Down = false;

bool isTape1Up = false;
bool isTape2Up = false;
bool isTape3Up = false;
bool isOnece = true;

void Blink_In_Order_Cyclically(){

  analogWrite(TAPE1_LED,Tape1Value);
  analogWrite(TAPE2_LED,Tape2Value);
  analogWrite(TAPE3_LED,Tape3Value);
  
  Tape1Value += blinkSpeed_Tape1; 

  if(Tape1Value >= 254){
    isTape1Up = true;
    isTape1 = true;
    blinkSpeed_Tape1 = 0;
  }

  if(isTape1Up){
    if(Tape1Value <= 0){
      isTape1Down = true;
      blinkSpeed_Tape1 = 0;
    }
  }
  
  if(isTape1 || isTape1Down){ Tape2Value += blinkSpeed_Tape2; }
  
 
  if(Tape2Value >= 254){
    if(isOnece){
      isTape2Up = true;
      isTape2 = true;
      blinkSpeed_Tape2 = 0;
      isOnece = false;
    }
  }
  

  if(isTape2Up){
    if(Tape2Value <= 0){
      isTape2Down = true;
      blinkSpeed_Tape2 = 0;
    }
  }
  
  if(isTape2 || isTape2Down){ Tape3Value += blinkSpeed_Tape3; }

  if(!isTape3){
    if(Tape3Value >= 254){
      blinkSpeed_Tape3 = 0;
      blinkSpeed_Tape1 = -0.05;
      blinkSpeed_Tape2 = -0.05;
      blinkSpeed_Tape3 = -0.05;
      isTape1 = false;
      isTape2 = false;
      isTape3Up = true;
      isTape3 = true;
      
    }
  }

  if(isTape3Up){
    if(Tape3Value <= 0){
      isTape3Down = true;
      blinkSpeed_Tape3 = 0;
    }
  }
  


  if(isTape3Down){
    isTape1 = false;
    isTape2 = false;
    isTape3 = false;
    
    Tape1Value = 0;
    Tape2Value = 0;
    Tape3Value = 0;
    blinkSpeed_Tape1 = 0.05;
    blinkSpeed_Tape2 = 0.05;
    blinkSpeed_Tape3 = 0.05;
    
    isTape1Up = false;
    isTape2Up = false;
    isTape3Up = false;

    isOnece = true;
    
    isTape1Down = false;
    isTape2Down = false;
    isTape3Down = false;
    
  }
}

