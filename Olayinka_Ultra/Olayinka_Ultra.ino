#include <Ultrasonic.h>
#define RELAY 5

/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */
Ultrasonic ultrasonic(3, 2);
void setup() {
  // put your setup code here, to run once:
pinMode(RELAY,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int measure=ultrasonic.read();
Serial.println("This is the distance read "+(String)measure);
if(measure<10){
  digitalWrite(RELAY,HIGH);
  Serial.println("Distance too Close");
}
else{
  digitalWrite(RELAY,LOW);
  Serial.println("Distance Okay");
}
delay(500);
}
