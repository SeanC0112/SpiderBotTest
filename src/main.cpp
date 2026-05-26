#include <Arduino.h>
#include <ESP32Servo.h>

// f:front, b:back, l:left, r:right, h:horizontal, v:vertical, i:inner, o:outer

int flh = 4;
int flvi = 36;
int flvo = 37;

Servo flhServo;
Servo flviServo;
Servo flvoServo;

int frh = 42;
int frvi = 17;
int frvo = 7;

Servo frhServo;
Servo frviServo;
Servo frvoServo;

int blh = 14;
int blvi = 13;
int blvo = 12;

Servo blhServo;
Servo blviServo;
Servo blvoServo;

int brh = 35;
int brvi = 18;
int brvo = 21;

Servo brhServo;
Servo brviServo;
Servo brvoServo;

void setup()
{
  Serial.begin(115200);
  delay(1000);
  // put your setup code here, to run once:
  // ESP32PWM::allocateTimer(0);
  // ESP32PWM::allocateTimer(1);
  // ESP32PWM::allocateTimer(2);
  // ESP32PWM::allocateTimer(3);

  // ESP32PWM::allocateTimer(4);
  // ESP32PWM::allocateTimer(5);
  // ESP32PWM::allocateTimer(6);
  // ESP32PWM::allocateTimer(7);

  Serial.printf("Attaching flhServo to pwm %d\n", flhServo.attach(flh, 500, 2400));
  Serial.printf("Attaching flviServo to pwm %d\n", flviServo.attach(flvi, 500, 2400));
  Serial.printf("Attaching flvoServo to pwm %d\n", flvoServo.attach(flvo, 500, 2400));

  Serial.printf("Attaching frhServo to pwm %d\n", frhServo.attach(frh, 500, 2400));
  Serial.printf("Attaching frviServo to pwm %d\n", frviServo.attach(frvi, 500, 2400));
  Serial.printf("Attaching frvoServo to pwm %d\n", frvoServo.attach(frvo, 500, 2400));

  Serial.printf("Attaching blhServo to pwm %d\n", blhServo.attach(blh, 500, 2400));
  Serial.printf("Attaching blviServo to pwm %d\n", blviServo.attach(blvi, 500, 2400));
  Serial.printf("Attaching blvoServo to pwm %d\n", blvoServo.attach(blvo, 500, 2400));

  Serial.printf("Attaching brhServo to pwm %d\n", brhServo.attach(brh, 500, 2400));
  Serial.printf("Attaching brviServo to pwm %d\n", brviServo.attach(brvi, 500, 2400));
  Serial.printf("Attaching brvoServo to pwm %d\n", brvoServo.attach(brvo, 500, 2400));
}

void loop()
{
  // put your main code here, to run repeatedly:
  // flhServo.write(90);
  // sleep(1);
  // flhServo.write(0);
  // sleep(1);
}
