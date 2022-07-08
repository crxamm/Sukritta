#define LED1 32
#define LED2 33
void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}


void loop() {
  for(int i=0;i<=10 ; i++) {
  digitalWrite(LED1,HIGH);
  delay(100);
  digitalWrite(LED1,LOW);
  delay(100);
  for(int i=0;i<=10 ; i++) {
  digitalWrite(LED2,HIGH);
  delay(100);
  digitalWrite(LED2,LOW);
  delay(100);

  }
  }
}
