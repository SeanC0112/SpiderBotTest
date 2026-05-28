#ifndef triplejointedleg_h
#define triplejointedleg_h
#include <ESP32Servo.h>

struct pose3D
{
    float x;
    float y;
    float z;

    pose3D(float x, float y, float z) : x(x), y(y), z(z) {}
};

struct legState
{
    float hAngle;
    float viAngle;
    float voAngle;

    legState(float hAngle, float viAngle, float voAngle) : hAngle(hAngle), viAngle(viAngle), voAngle(voAngle) {}
};

struct legConfig
{
    float innerLength;
    float middleLength;
    float outerLength;

    int hPin;
    int viPin;
    int voPin;

    float hOffset;
    float viOffset;
    float voOffset;

    legConfig(float innerLength, float middleLength, float outerLength,
              int hPin, int viPin, int voPin,
              float hOffset = 0, float viOffset = 0, float voOffset = 0) : innerLength(innerLength), middleLength(middleLength), outerLength(outerLength),
                                                                           hPin(hPin), viPin(viPin), voPin(voPin),
                                                                           hOffset(hOffset), viOffset(viOffset), voOffset(voOffset) {}
};

class tripleJointedLeg
{
private:
    Servo h;
    Servo vi;
    Servo vo;

    legConfig config;

    pose3D currentPose;
    pose3D targetPose;

    legState currentState;
    legState targetState;

public:
    tripleJointedLeg(legConfig config);
    ~tripleJointedLeg();

    void moveToPose(pose3D targetPose);
    void moveToState(legState targetState);

    pose3D getCurrentPose();
    legState getCurrentState();

    void updateConfig(legConfig newConfig);

    void setH(float angle);
    void setVI(float angle);
    void setVO(float angle);
};

#endif