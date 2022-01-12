#include <AFMotor.h>
#include<Servo.h>
#include "Ultrasonic.h"
#include<NewPing.h>

#define RIGHT A2
#define LEFT A3

AF_DCMotor f1(1);
AF_DCMotor b1(2);
AF_DCMotor fr(3);
AF_DCMotor br(4);

Ultrasonic ultrasonic(A0,A1);

int distance;
Servo myservo;

int pos =0;

void setup(){
  Serial.begin(9600);

  myservo.attach(10);
{
for(pos = 90; pos <= 180; pos += 1){
  myservo.write(pos);
  delay(15);
} for(pos = 180; pos >= 0; pos-= 1) {
  myservo.write(pos);
  delay(15);
}for(pos = 0; pos<=90; pos += 1) {
  myservo.write(pos);
  delay(15);
}
}

}


void loop(){
  delay(50);
  distance = ultrasonic.Ranging(CM);
  Serial.print("Object found at: ");
  Serial.print(distance);
  Serial.println("cm");


  
int Right_Value = digitalRead(RIGHT);
Serial.print("RIGHT");
Serial.println(Right_Value);

int Left_Value = digitalRead(LEFT);
Serial.print("LEFT");
Serial.println(Left_Value);


  if(((Right_Value==0)) && (distance>=4 && distance<=30) && (Left_Value==0)){
  f1.setSpeed(120);
  f1.run(FORWARD);
  b1.setSpeed(120);
  b1.run(FORWARD);
  fr.setSpeed(120);
  fr.run(FORWARD);
  br.setSpeed(120);
  br.run(FORWARD);
}
else if((Right_Value==1) && (Left_Value==0)) {
  f1.setSpeed(200);
  f1.run(FORWARD);
  b1.setSpeed(200);
  b1.run(FORWARD);
  fr.setSpeed(100);
  fr.run(BACKWARD);
  br.setSpeed(100);
  br.run(BACKWARD);
}else if((Right_Value==0)&&(Left_Value==1)) {
  f1.setSpeed(100);
  f1.run(BACKWARD);
  b1.setSpeed(100);
  b1.run(BACKWARD);
  fr.setSpeed(200);
  fr.run(FORWARD);
  br.setSpeed(200);
  br.run(FORWARD);
}else if((Right_Value==1)&&(Left_Value==1)) {
  f1.setSpeed(0);
  f1.run(RELEASE);
  b1.setSpeed(0);
  b1.run(RELEASE);
  fr.setSpeed(0);
  fr.run(RELEASE);
  br.setSpeed(0);
  br.run(RELEASE);
}else if(distance > 1 && distance < 4) {
  f1.setSpeed(0);
  f1.run(RELEASE);
  b1.setSpeed(0);
  b1.run(RELEASE);
  fr.setSpeed(0);
  fr.run(RELEASE);
  br.setSpeed(0);
  br.run(RELEASE);
 }else if(distance > 30){
  f1.setSpeed(0);
  f1.run(RELEASE);
  b1.setSpeed(0);
  b1.run(RELEASE);
  fr.setSpeed(0);
  fr.run(RELEASE);
  bl.setSpeed(0);
  bl.run(RELEASE);
 }
}