#include <tripleJointedLeg.h>
#include <ESP32Servo.h>

tripleJointedLeg::tripleJointedLeg(legConfig config)
{
    this->config = config;

    h.attach(config.hPin);
    vi.attach(config.viPin);
    vo.attach(config.voPin);
}

tripleJointedLeg::~tripleJointedLeg()
{
    h.detach();
    vi.detach();
    vo.detach();
}

void tripleJointedLeg::updateConfig(legConfig newConfig)
{
    h.detach();
    vi.detach();
    vo.detach();

    this->config = newConfig;

    h.attach(config.hPin);
    vi.attach(config.viPin);
    vo.attach(config.voPin);
}

void tripleJointedLeg::main()
{
    h.write(config.hOffset + targetState.hAngle);
    vi.write(config.viOffset + targetState.viAngle);
    vo.write(config.voOffset + targetState.voAngle);
}

void tripleJointedLeg::moveToPose(pose3D targetPose)
{
    this->targetPose = targetPose;
    this->targetState = calculateStateFromPose(targetPose);

    main();
}

void tripleJointedLeg::moveToState(legState targetState)
{
    this->targetState = targetState;
    this->targetPose = calculatePoseFromState(targetState);

    main();
}

pose3D tripleJointedLeg::getCurrentPose()
{
    legState currentState(-config.hOffset + h.read(), -config.viOffset + vi.read(), -config.voOffset + vo.read());
    return calculatePoseFromState(currentState);
}

legState tripleJointedLeg::getCurrentState()
{
    return legState(-config.hOffset + h.read(), -config.viOffset + vi.read(), -config.voOffset + vo.read());
}

void tripleJointedLeg::setH(float angle)
{
    targetState.hAngle = angle;
    targetPose = calculatePoseFromState(targetState);
    main();
}

void tripleJointedLeg::setVO(float angle)
{
    targetState.voAngle = angle;
    targetPose = calculatePoseFromState(targetState);
    main();
}

void tripleJointedLeg::setVI(float angle)
{
    targetState.viAngle = angle;
    targetPose = calculatePoseFromState(targetState);
    main();
}