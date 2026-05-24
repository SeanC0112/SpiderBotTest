#include <Arduino.h>
#include <ESP32Servo.h>

// f:front, b:back, l:left, r:right, h:horizontal, v:vertical, i:inner, o:outer

int flh = 6;
int flvi = 7;
int flvo = 15;

Servo flhServo;
Servo flviServo;
Servo flvoServo;

int frh = 41;
int frvi = 40;
int frvo = 39;

Servo frhServo;
Servo frviServo;
Servo frvoServo;

int blh = 14;
int blvi = 13;
int blvo = 12;

Servo blhServo;
Servo blviServo;
Servo blvoServo;

int brh = 19;
int brvi = 20;
int brvo = 21;

Servo brhServo;
Servo brviServo;
Servo brvoServo;

void setup()
{
  // put your setup code here, to run once:
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  flhServo.attach(flh, 500, 2400);
  flviServo.attach(flvi, 500, 2400);
  flvoServo.attach(flvo, 500, 2400);

  frhServo.attach(frh, 500, 2400);
  frviServo.attach(frvi, 500, 2400);
  frvoServo.attach(frvo, 500, 2400);

  blhServo.attach(blh, 500, 2400);
  blviServo.attach(blvi, 500, 2400);
  blvoServo.attach(blvo, 500, 2400);

  brhServo.attach(brh, 500, 2400);
  brviServo.attach(brvi, 500, 2400);
  brvoServo.attach(brvo, 500, 2400);
}

void loop()
{
  // put your main code here, to run repeatedly:
}
