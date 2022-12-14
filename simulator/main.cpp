#include <iostream>

#include "Graphics.h"
#include "Robot.h"

int main() {
    Graphics gr{};

    if(!gr.Init(1000, 1000, "Improvise Adapt Overcome")) {
        std::cout << "Failed to init graphics." << std::endl;
        return -1;
    } else {
        std::cout << "Initialized graphics." << std::endl;
    }

    Image img = Image(gr.GetRenderer(), "assets/simple_path.png", 0, 0, 1000, 1000);
    Robot rb = Robot(500, 500, 130.0);

    while(!gr.WantToClose()) {
        rb.Probe(img);

        gr.Update();

        img.Render(gr.GetRenderer());
        rb.RenderRobot(gr.GetRenderer());

        gr.EndFrame();

        rb.StepSim();
    }

    return 0;
}
