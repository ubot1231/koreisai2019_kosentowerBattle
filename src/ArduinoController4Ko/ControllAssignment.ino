
void ControllAsignment(){
  //while (Serial.available() <= 0)
  
  //Right
  if(digitalRead(STATE_pin[0]) == LOW){
    digitalWrite(LED_pin[0],HIGH);
    Keyboard.press((player1 == true) ? 'f' : 'j');
    delay(100);
    Keyboard.releaseAll();
  }
  
  //Rotate
  if(digitalRead(STATE_pin[1]) == LOW){
    digitalWrite(LED_pin[1],HIGH);
    Keyboard.press((player1 == true) ? 't' : 'i');
    delay(100);
    Keyboard.releaseAll();
    
    while(digitalRead(STATE_pin[1]) == LOW);
  }
  
  //Left
  if(digitalRead(STATE_pin[2]) == LOW){
    digitalWrite(LED_pin[2],HIGH);
    Keyboard.press((player1 == true) ? 'h' : 'l');
    delay(100);
    Keyboard.releaseAll();
  }
  
  //Drop
  if(digitalRead(STATE_pin[3]) == LOW){
    digitalWrite(LED_pin[3],HIGH);
    Keyboard.press((player1 == true) ? 'g' : 'k');
    delay(100);
    Keyboard.releaseAll();
    
    while(digitalRead(STATE_pin[2]) == LOW);
  }

}

