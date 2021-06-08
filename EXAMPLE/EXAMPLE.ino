void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int a;
  int b;
  float c;
  int d;
  float e;
  a=pow(2,7);
  Serial.println((String)a);
  b=5;
  d=3;
  c=a*b;
  Serial.println((String)c);
 e=c/d;
 Serial.println((String)e);
}

void loop() {
  // put your main code here, to run repeatedly:

}
