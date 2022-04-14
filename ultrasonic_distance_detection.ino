#include <SoftwareSerial.h>
#define GREEN_LED_PIN 13
#define YELLOW_LED_PIN 12 
#define RED_LED_PIN 11
int TrigPin = 7;
int EchoPin = 8;
int TxD = 9;
int RxD = 10;
String value;
int state = 1;
SoftwareSerial bluetooth(TxD, RxD);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
 if(state == 1){
 long duration, distance;
 digitalWrite(TrigPin, LOW);  
 delayMicroseconds(2); 
 digitalWrite(TrigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(TrigPin, LOW);
 duration = pulseIn(EchoPin, HIGH);
 distance = (duration/2) / 29.1;
 Serial.print(distance);
 Serial.print("cm   |  ");
 if(distance<50 && distance>0)
 {
  Serial.println("Close to the object!");
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
 }
 else if(distance>=50 && distance<=100)
 {
  Serial.println("There is an object near!");
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(YELLOW_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, LOW);
 }
 else{
  Serial.println("No object detected!");
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);
 }
 delay(1000);
 }
 if(bluetooth.available())
   {
    value = bluetooth.readString();
    value.toLowerCase();   
    Serial.println(value);
    if(value == "turn off")
    {
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, LOW) ;
      digitalWrite(GREEN_LED_PIN, LOW);
      state = 0;
    }
    else 
      if(value == "turn on")
        {
         digitalWrite(RED_LED_PIN, HIGH);
         digitalWrite(YELLOW_LED_PIN, HIGH);
         digitalWrite(GREEN_LED_PIN, HIGH);
         state = 1;
        }
   }
}
