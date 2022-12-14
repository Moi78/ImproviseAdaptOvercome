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

class Robot {
public:
    Robot(int spawn_x, int spawn_y, double angle);
    ~Robot();

    void RenderRobot(SDL_Renderer* rndr);

    void StepForward();

    void Probe(Image& plate);
    void SetAngle(float angle);

private:
    float m_x, m_y;
    double m_angle;

    std::array<bool, 4> m_sensor_states;
    std::array<Polar, 4> m_sensor_local_pos;
};


#endif //IMPROVISE_ADAPT_OVERCOME_ROBOT_H
