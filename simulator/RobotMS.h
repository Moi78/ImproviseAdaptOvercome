#ifndef IMPROVISE_ADAPT_OVERCOME_ROBOTMS_H
#define IMPROVISE_ADAPT_OVERCOME_ROBOTMS_H

#include "Robot.h"

class RobotMS : public Robot {
public:
    RobotMS(int spawnx, int spawny, int angle);
    virtual ~RobotMS();

    void RenderRobot(SDL_Renderer* rndr) override;
    void StepSim() override;
    void Probe(Image& plate) override;

private:
    std::array<uint8_t, 4> m_sensors_state;
};


#endif //IMPROVISE_ADAPT_OVERCOME_ROBOTMS_H
