//
// Created by mathis on 07/12/22.
//

#ifndef IMPROVISE_ADAPT_OVERCOME_ROBOT_H
#define IMPROVISE_ADAPT_OVERCOME_ROBOT_H

#include <iostream>
#include <array>
#include "SDL.h"

#include "Image.h"

struct Polar {
    float r;
    float ang;
};

enum States {
    DEBUT
};

class Robot {
public:
    Robot(int spawn_x, int spawn_y, double angle);
    ~Robot();

    virtual void RenderRobot(SDL_Renderer* rndr);

    virtual void StepSim();

    virtual void Probe(Image& plate);
    virtual void SetAngle(float angle);
    virtual void GoForward(float step);

protected:
    float m_x, m_y;
    double m_angle;

    int m_lastKnownSensor;

    std::array<bool, 4> m_sensor_states;
    std::array<Polar, 4> m_sensor_local_pos;
};


#endif //IMPROVISE_ADAPT_OVERCOME_ROBOT_H
