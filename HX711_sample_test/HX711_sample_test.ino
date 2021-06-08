#include "HX711.h"
#include "ESP8266WiFi.h"
#include "WiFiClient.h"
#include "ESP8266WebServer.h"
//#include <ESP8266mDNS.h>
#include "EEPROM.h"
#define GAS_SENSOR A0
#define BUZZER D7

HX711 scale;
/* Put your SSID & Password */
const char* ssid = "GasWeigh";  // Enter SSID here
const char* password = "12345678";  //Enter Password here
// HX711 circuit wiring
const int HX711_dout = D5; //mcu > HX711 dout pin
const int HX711_sck = D6; //mcu > HX711 sck pin
/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
//WiFiServer server(80);
ESP8266WebServer server(81);
//WiFiClient client;
bool scaleStatus=false,gasStatus=false,wifiStatus=false,lowGas=false;
float scaleValue=0,lowThreshold=0.1;
int analogSensor=0,threshold=0,gasAlarm=0,emptyCylinder=0,filledCylinder=0,loopCount=0;
String scaleString,gasString,configData[3];



void setup() {
  Serial.begin(9600);
  EEPROM.begin(512);
  delay(1000);
  emptyCylinder=readFromEEPROM(0);
  filledCylinder=readFromEEPROM(1);
  int readsense=EEPROM.read(255);
  if (readsense==255 || readsense==0){
    readsense=1;
  }
  threshold=(6-readsense)*40;
  Serial.println("Threshold is: "+(String)threshold);
  Serial.println("Set up started");
  pinMode(BUZZER,OUTPUT);
  if(setupWifi())wifiStatus=true;
  if(setupScale())scaleStatus=true;
  if(setupGas())gasStatus=true;
  Serial.println("All set up complete");
  get_config();
}

void loop(){
server.handleClient();
//  if(wifiStatus){
//  client = server.available();
//  // wait for a client (web browser) to connect
//  if (client)
//  {
//    Serial.println("\n[Client connected]");
//    while (client.connected())
//    {
//      // read line by line what the client (web browser) is requesting
//      if (client.available())
//      {
//        String line = client.readStringUntil('\n');
//        Serial.print(line);
//        // wait for end of client's request, that is marked with an empty line
//        if (line.indexOf("GET_UPDATE")!=-1)
//        {
//          client.println("7500,0");
//          break;
//        }
//      }
//    }
//    delay(1); // give the web browser time to receive the data
//
//    // close the connection:
//    client.stop();
//    Serial.println("[Client disonnected]");
//  }
//  }
//client = server.available();
//if(client)Serial.println("Client connected");
if(loopCount> 100){
 Serial.println("this is loop count "+(String)loopCount+" loop count reset");
getResponse();
loopCount=0;
}
else{
  Serial.println("this is loop count "+(String)loopCount);
  loopCount++;
  delay(5);
}
}
