int LED1=16;
int LED2=15;
int LDR=A0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value=analogRead(LDR);

  Serial.println(value);
  if(value==1024)
  {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
  }
  else
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2,HIGH);
  }
}