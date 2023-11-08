#include <Servo.h>

Servo servo;
int trig=12;
int echo=13;
int buzzer=11;
float distance;
float duration;

void setup() {
  
  Serial.begin (9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  servo.attach(8);

}

void loop() {
  
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.017;
  Serial.print("Distance=");
  Serial.println(distance);

  if (distance<=14)
  {
//    Serial.println("WARNING !!");
    digitalWrite(buzzer,HIGH);
//    delay(4000);
//    digitalWrite(buzzer,LOW);
  }
  else
  {
    digitalWrite(buzzer,LOW);
  }
  
  if (distance<12)
  {
    Serial.println("Gate Opening");
    servo.write(90);
  }
  else
  {
    servo.write(0);
  }
  
}
