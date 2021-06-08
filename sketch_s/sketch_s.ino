void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//for(byte x=0;x<=100;x+=5){
//  Serial.println(x);
//}
int x=100;
while(x<100){
  Serial.println(x);
  x+=2;
}
x=100;
Serial.println("while loop completed");
do{
 Serial.println(x);
 x+=3;
}while(x<100);
Serial.println("do while loop completed");
//Serial.println(1,100);

}

void loop() {
  // put your main code here, to run repeatedly:

}
