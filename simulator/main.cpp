#include <iostream>
#include <thread>
#include <chrono>

#include "Graphics.h"
#include "Robot.h"
#include "RobotMS.h"

int main() {
    Graphics gr{};

    if(!gr.Init(1000, 1000, "Improvise Adapt Overcome")) {
        std::cout << "Failed to init graphics." << std::endl;
        return -1;
    } else {
        std::cout << "Initialized graphics." << std::endl;
    }

    Image img = Image(gr.GetRenderer(), "assets/simple_path.png", 0, 0, 1000, 1000);
    //Robot rb = Robot(860, 145, 90.0);
    RobotMS rb = RobotMS(790, 145, 130.0);

    while(!gr.WantToClose()) {
        std::thread probing_thread([](Robot& rb, Image& img){
            rb.Probe(img);
        }, std::ref(rb), std::ref(img));

        std::thread rendering_thread([](Graphics& gr, Image& img, Robot& rb){
            gr.Update();

            img.Render(gr.GetRenderer());
            rb.RenderRobot(gr.GetRenderer());

            gr.EndFrame();
        }, std::ref(gr), std::ref(img), std::ref(rb));

        probing_thread.join();
        rendering_thread.join();

        rb.StepSim();
    }

    return 0;
}
