//
// Created by mathis on 07/12/22.
//

#include "Robot.h"

Robot::Robot(int spawn_x, int spawn_y, double angle) {
    m_x = spawn_x;
    m_y = spawn_y;

    m_angle = angle;

    m_sensor_states = {false, false, false, false};
    m_sensor_local_pos[0] = {28.5, 90.0};
    m_sensor_local_pos[1] = {9.5, 90.0};
    m_sensor_local_pos[2] = {9.5, -90.0};
    m_sensor_local_pos[3] = {28.5, -90.0};
}

Robot::~Robot() {

}

void Robot::RenderRobot(SDL_Renderer *rndr) {
    //X 24.3
    //Y 25.5

    SDL_Rect r{};
    r.x = m_x - 120;
    r.y = m_y - 120;
    r.w = 240;
    r.h = 250;

    SDL_SetRenderDrawColor(rndr, 255, 0, 0, 255);

    SDL_RenderDrawLine(rndr, m_x, m_y, m_x + 100 * cos(m_angle * (3.141592 / 180.0)), m_y + 100 * sin(m_angle * (3.141592 / 180.0)));

    SDL_SetRenderDrawColor(rndr, 255, 0, 255, 255);
    SDL_RenderDrawRect(rndr, &r);

    int i = 0;
    for(auto &p : m_sensor_local_pos) {
        float locX = p.r * cos((p.ang + m_angle) * (3.141592 / 180.0));
        float locY = p.r * sin((p.ang + m_angle) * (3.141592 / 180.0));

        SDL_Rect s{};
        s.x = locX + m_x - 2;
        s.y = locY + m_y - 2;
        s.w = 4;
        s.h = 4;

        if(m_sensor_states[i]) {
            SDL_SetRenderDrawColor(rndr, 0, 128, 0, 255);
        } else {
            SDL_SetRenderDrawColor(rndr, 255, 0, 0, 255);
        }

        SDL_RenderFillRect(rndr, &s);

        i++;
    }
}

void Robot::StepForward() {
    float coef_x = cos(m_angle * (3.141592 / 180.0));
    float coef_y = sin(m_angle * (3.141592 / 180.0));

    //m_x += 0.1 * coef_x;
    //m_y += 0.1 *coef_y;

    m_angle += 0.1;
}

void Robot::Probe(Image &plate) {
    int i = 0;
    for(auto& p : m_sensor_local_pos) {
        float locX = p.r * cos((p.ang + m_angle) * (3.141592 / 180.0)) + m_x;
        float locY = p.r * sin((p.ang + m_angle) * (3.141592 / 180.0)) + m_y;

        Color c = plate.GetPixel(locX, locY);
        m_sensor_states[i] = c.r != 0.0f;

        i++;
    }
}

void Robot::SetAngle(float angle) {
    m_angle = angle;
}