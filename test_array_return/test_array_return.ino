#include <EEPROM.h>
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
EEPROM.begin(512);
Serial.println("about to start");
writeToEEPROM("1000","5000");
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("about to start");
writeToEEPROM("1000","5000");
delay(10000);
}

void readFromEEPROM(byte readType){
byte higherByte=EEPROM.read(readType*2);
byte lowerByte=EEPROM.read(readType*2+1);
Serial.println("higher byte is: "+String(higherByte)+" and lower byte is: "+String(lowerByte));
int temp=0x0000 | higherByte;
int originalVal=(higherByte<<8) | lowerByte;
if(!readType)Serial.println("empty value is: "+String(originalVal));
else Serial.println("fill value is: "+String(originalVal));
}
void writeToEEPROM(String empty,String filled){
  int emptyInt=empty.toInt();
  int filledInt=filled.toInt();
  Serial.println("The result of the conversion are: "+(String)emptyInt+" and "+(String)filledInt);
  byte * rs=bytearray(emptyInt);
  EEPROMwriter(rs,0);
  delay(2000);
  readFromEEPROM(0);
  rs=bytearray(filledInt);
  EEPROMwriter(rs,2);
  delay(2000);
  readFromEEPROM(1);
}

void EEPROMwriter(byte * data,int startVal){
  int len=sizeof(data)/(2*sizeof(data[0]));
  Serial.println("array length is: "+String(len));
    for(byte k=0;k<len;k++){
    EEPROM.write(startVal+k,data[k]);
    Serial.println("wrote value: "+String(data[k]));
  }
  EEPROM.commit();
}
byte * bytearray(int big_num){
  byte rst[2];
  int temp=0x0000|big_num;
  Serial.println("temp:");
  Serial.println(temp,BIN);
  rst[0]=temp >> 8;
  Serial.println("result0:");
  Serial.println(rst[0],BIN);
  Serial.println(rst[0]);
  rst[1]=temp & 0x00FF;
  Serial.println("result1:");
  Serial.println(rst[1],BIN);
  Serial.println(rst[0]);
  return &rst[0];
}
void readFromEEPROM(){
  
}
