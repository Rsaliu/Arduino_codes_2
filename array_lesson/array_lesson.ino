
int numbers[][7]={{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};

void setup() {
  // put your setup code here, to run once:

  for(int x=0;x<7;x++){
    pinMode(x+2,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
for(byte x=0;x<10;x++){
  for(byte z=0;z<20;z++){
  for(byte y=0;y<7;y++){
    digitalWrite(y+2,numbers[x][y]);
    delay(10);
  }
  }
}
}
