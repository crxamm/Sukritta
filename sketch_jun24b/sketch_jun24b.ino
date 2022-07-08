int LED1 = 23;
int LED2 = 22;
int LED3 = 18;
int LED4 = 19;

const int sw1 = 4 ;
const int sw2 = 5 ;
void setup() {
  // put your setup code here, to run once:
pinMode (LED1,OUTPUT);
pinMode (LED2,OUTPUT);
pinMode (LED3,OUTPUT);
pinMode (LED4,OUTPUT);

pinMode (sw1,INPUT);
pinMode (sw2,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (LED1,HIGH) ;
delay (90) ;
digitalWrite (LED1,LOW) ;
delay (90) ;
digitalWrite (LED1,LOW) ;
delay (3000) ;
digitalWrite (LED1,HIGH) ;
delay (3000) ;
digitalWrite (LED1,HIGH) ;
delay (90) ;
digitalWrite (LED1,LOW) ;
delay (90) ;
digitalWrite (LED1,LOW) ;
delay (3000) ;
digitalWrite (LED1,HIGH) ;
delay (3000) ;

int sw1 = digitalRead (sw1);
int sw2 = digitalRead (sw2);
 if(sw1 == HIGH){
    ledone();
  }else if (sw2 == LOW){
    ledtwo();
  }
}

void ledone() {
digitalWrite(LED1, HIGH); 
digitalWrite(LED2, HIGH); 
}
void ledtwo() {
digitalWrite(LED1, LOW); 
digitalWrite(LED2, LOW);
}
