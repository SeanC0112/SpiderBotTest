#ifndef triplejointedleg_h
#define triplejointedleg_h
#include <ESP32Servo.h>

class tripleJointedLeg
{
private:
    Servo h;
    Servo vi;
    Servo vo;

public:
    tripleJointedLeg(/* args */);
    ~tripleJointedLeg();
};

#endif