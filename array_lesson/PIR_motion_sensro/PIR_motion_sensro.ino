#define PIR 2
#define BUZZER 8

void setup() {
  // put your setup code here, to run once:
pinMode(PIR,INPUT_PULLUP);
pinMode(BUZZER,OUTPUT);
Serial.begin(9600);
}

void loop() {
  int pir_reader=digitalRead(PIR);
  Serial.print(pir_reader);
  if(pir_reader)digitalWrite(BUZZER,HIGH);
  delay(2000);
  digitalWrite(BUZZER,LOW);
  // put your main code here, to run repeatedly:

}
