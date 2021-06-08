bool setupWifi(){
//  wifi_station_disconnect();
// wifi_set_opmode(0x02);
// WiFi.mode(WIFI_AP_STA);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  Serial.println("setting up Wifi");
  delay(1000);
  IPAddress ipAddress=WiFi.softAPIP();
  Serial.println("my IP address is:");
  Serial.println(ipAddress);
  server.on("/", handle_OnConnect);
  server.on("/weightconfig", handleWeightConfig);
  server.on("/gasconfig", handleGasConfig);
  server.on("/get_update", handle_update);
  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("HTTP server started");
  return true;
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

void handleWeightConfig(){
  String empty=server.arg("empty");
  String filled=server.arg("filled");
  Serial.println("empty is: "+empty+" and filled is: "+filled);
  server.send(200,"text/plain","OK");
  writeToEEPROM(empty,filled);
  get_config();
}

void handleGasConfig(){
  String sensitivity=server.arg("sensitivitylevel");
  Serial.println("sensitivity is:  "+sensitivity);
  server.send(200,"text/plain","OK");
  writeSenseToEEPROM(sensitivity);
  get_config();
}
//
void handle_update(){
  Serial.println("client requests for update");
  server.send(200,"text/plain",scaleString+","+gasString+","+configData[0]+","+configData[1]+","+configData[2]);
}

void get_config(){
Serial.println("client requests for config"); 
  configData[0]=(String)readFromEEPROM(0);
  configData[1]=(String)readFromEEPROM(1);
  configData[2]=(String)EEPROM.read(255);
  server.send(200,"text/plain",configData[0]+","+configData[1]+","+configData[2]);
}

void handle_OnConnect(){
  //getGas();
  //getScale();
  Serial.println("client connected to home");
  server.send(200,"text/plain","you are welcome");
  
}

String getResponse(){
  getGas();
  getScale();
  if(gasStatus) gasString=(String)gasAlarm;
  else gasString= "not_found";
  if(scaleStatus)scaleString=(String)scaleValue;
  else scaleString= "not_found";
  Serial.println("data to be sent is: "+scaleString+","+gasString);
}
