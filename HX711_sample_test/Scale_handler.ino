bool setupScale(){
 scale.begin(HX711_dout, HX711_sck);
  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  if (scale.wait_ready_timeout(1000)) {
    scaleValue = scale.get_units(10);
    Serial.print("Weight: ");
    Serial.println(scaleValue, 2);
} else {
    Serial.println("HX711 not found.");
}
  Serial.println(scale.read());     // print a raw reading from the ADC
  scale.set_scale(23.58);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();                // reset the scale to 0
  Serial.println("tare set");
  return true;
}

void getScale(){
  gasStatus=false;
  scale.power_up();
  delay(500);
  Serial.print("\t| average:\t");
    if (scale.wait_ready_timeout(1000)) {
    scaleValue = scale.get_units(20);
    Serial.print("Weight: ");
    Serial.println(scaleValue, 2);
    if(scaleValue<0)scaleValue=0;
    if(scaleValue>60000)scaleValue=0;
  //Serial.println(scaleValue, 1);
  checkLowGas();
    gasStatus=true;
} else {
    Serial.println("HX711 not found.");
}
  //scaleValue=scale.get_units(10);

  scale.power_down();  
  delay(500);
  
}
void checkLowGas(){
    int lowWeight=emptyCylinder+(lowThreshold*(filledCylinder-emptyCylinder));
    if(scaleValue>emptyCylinder && scaleValue<lowWeight)lowGasAlarm(true);
    else lowGasAlarm(false);
}
