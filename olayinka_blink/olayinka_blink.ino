void setup() {
 pinMode (8, OUTPUT);
 pinMode (9, OUTPUT); // put your setup code here, to run once:

}

void loop() {
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite (9, HIGH);
  delay (2000);
  // put your main code here, to run repeatedly:
  digitalWrite (8, LOW);
  digitalWrite (9, LOW);
  delay(1000);
}
