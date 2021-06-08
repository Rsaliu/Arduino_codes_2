bool setupGas(){
  analogSensor = analogRead(GAS_SENSOR);
  if(analogSensor)return true;
  else return false;
}

void getGas(){
  gasStatus=false;
  analogSensor = analogRead(GAS_SENSOR);
  Serial.print("GAS_SENSOR: ");
  Serial.println(analogSensor);
  if(analogSensor>0){
  if(analogSensor>threshold){
    gasAlarm=1;
    leakAlarm(true);
  }
  else {
    gasAlarm=0;
    leakAlarm(false);
  }
  gasStatus=true;
  }
  
}
