#include "RobotMS.h"

RobotMS::RobotMS(int spawnx, int spawny, int angle) : Robot(spawnx, spawny, angle) {

}

RobotMS::~RobotMS() {

}

void RobotMS::RenderRobot(SDL_Renderer *rndr) {
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

        SDL_SetRenderDrawColor(rndr, m_sensors_state[i], 0, 128, 255);
        SDL_RenderFillRect(rndr, &s);

        i++;
    }
}

void RobotMS::Probe(Image &plate) {
    const float filter_size = 5;

    int i = 0;
    for(auto& p : m_sensor_local_pos) {
        float locX = p.r * cos((p.ang + m_angle) * (3.141592 / 180.0)) + m_x;
        float locY = p.r * sin((p.ang + m_angle) * (3.141592 / 180.0)) + m_y;

        int mean = 0;
        int counter = 0;
        for(int x = -filter_size; x <= filter_size; x++) {
            for(int y = -filter_size; y <= filter_size; y++) {
                Color c = plate.GetPixel(locX + x, locY + y);
                mean += c.r;
                counter++;
            }
        }
        mean /= counter;

        m_sensors_state[i] = mean;

        i++;
    }
}

void RobotMS::StepSim() {
    GoForward(0.1);

    float diff = (m_sensors_state[1] - m_sensors_state[2]) / 255.0;
    m_angle += 0.1f * diff;
}