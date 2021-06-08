void leakAlarm(bool state){
  if(state)digitalWrite(BUZZER,HIGH);
  else digitalWrite(BUZZER,LOW);
}

void lowGasAlarm(bool state){
   if(state)tone(BUZZER,1000);
  else noTone(BUZZER);
}
