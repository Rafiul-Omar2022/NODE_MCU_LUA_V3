int LASER=4;
int LDR=A0;
int LED = 16;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(LASER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value=analogRead(LDR);
  digitalWrite(LASER, HIGH);
  Serial.println(value);
  if(value<=1000)
  {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}