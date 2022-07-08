int LED1 = 23 ;
int LED2 = 22 ;
int LED3 = 18 ;
int LED4 = 19 ;

void setup() {
pinMode (LED1,OUTPUT);
pinMode (LED2,OUTPUT);
pinMode (LED3,OUTPUT);
pinMode (LED4,OUTPUT);
}

void loop() {
digitalWrite (LED1,HIGH) ;
delay(90);
digitalWrite (LED1,LOW) ;
delay(90);
digitalWrite (LED2,LOW) ;
delay(3000);
digitalWrite (LED2,HIGH) ;
delay(3000);
digitalWrite (LED3,HIGH) ;
delay(90);
digitalWrite (LED3,LOW) ;
delay(90);
digitalWrite (LED4,LOW) ;
delay(3000);
digitalWrite (LED4,HIGH) ;
delay(3000);
}
