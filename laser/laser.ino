int LASER=4;
void setup() {
  // put your setup code here, to run once:
  pinMode(LASER,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(LASER,HIGH);
 delay(1000);

}
