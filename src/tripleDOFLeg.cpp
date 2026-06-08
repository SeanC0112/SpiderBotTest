#include <tripleDOFLeg.h>
#include <ESP32Servo.h>
#include <math.h>
#include <util.h>

using namespace Util;

tripleDOFLeg::tripleDOFLeg(legConfig config)
{
    this->config = config;

    h.attach(config.hPin);
    vi.attach(config.viPin);
    vo.attach(config.voPin);
}

tripleDOFLeg::~tripleDOFLeg()
{
    h.detach();
    vi.detach();
    vo.detach();
}

void tripleDOFLeg::updateConfig(legConfig newConfig)
{
    h.detach();
    vi.detach();
    vo.detach();

    this->config = newConfig;

    h.attach(config.hPin);
    vi.attach(config.viPin);
    vo.attach(config.voPin);
}

void tripleDOFLeg::main()
{
    h.write(config.hOffset + targetState.hAngle);
    vi.write(config.viOffset + targetState.viAngle);
    vo.write(config.voOffset + targetState.voAngle);
}

void tripleDOFLeg::moveToPose(pose3D targetPose)
{
    this->targetPose = targetPose;
    this->targetState = calculateStateFromPose(targetPose);

    main();
}

void tripleDOFLeg::moveToState(legState targetState)
{
    this->targetState = targetState;
    this->targetPose = calculatePoseFromState(targetState);

    main();
}

pose3D tripleDOFLeg::getCurrentPose()
{
    legState currentState(-config.hOffset + h.read(), -config.viOffset + vi.read(), -config.voOffset + vo.read());
    return calculatePoseFromState(currentState);
}

legState tripleDOFLeg::getCurrentState()
{
    return legState(-config.hOffset + h.read(), -config.viOffset + vi.read(), -config.voOffset + vo.read());
}

void tripleDOFLeg::setH(float angle)
{
    targetState.hAngle = angle;
    targetPose = calculatePoseFromState(targetState);
    main();
}

void tripleDOFLeg::setVO(float angle)
{
    targetState.voAngle = angle;
    targetPose = calculatePoseFromState(targetState);
    main();
}

void tripleDOFLeg::setVI(float angle)
{
    targetState.viAngle = angle;
    targetPose = calculatePoseFromState(targetState);
    main();
}

// Inverse Kinematics who?
// Shit this is fucking forward kinematics
pose3D tripleDOFLeg::calculatePoseFromState(legState state)
{
    float angle = state.hAngle;
    float outerMagnitude = sqrtf(config.outerLength * config.outerLength + config.middleLength * config.middleLength - 2 * config.outerLength * config.middleLength * cosf(state.voAngle));
    float z = outerMagnitude * sinf(state.viAngle + state.voAngle);
    float flatMagnitude = outerMagnitude * cosf(state.viAngle + state.voAngle) + config.innerLength;
    float x = sinf(angle) * flatMagnitude;
    float y = cosf(angle) * flatMagnitude;
    return pose3D(x, y, z);
}

// Inverse kinematics who? fr this time
legState tripleDOFLeg::calculateStateFromPose(pose3D pose)
{
}