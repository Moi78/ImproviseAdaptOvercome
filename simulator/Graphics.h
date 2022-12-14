//
// Created by mathis on 07/12/22.
//

#ifndef IMPROVISE_ADAPT_OVERCOME_GRAPHICS_H
#define IMPROVISE_ADAPT_OVERCOME_GRAPHICS_H

#include <memory>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "Image.h"

class Graphics {
public:
    Graphics();
    ~Graphics();

    bool Init(int w, int h, std::string title);

    void Update();
    void EndFrame();

    bool WantToClose();

    SDL_Renderer* GetRenderer() { return m_rndr; }

private:
    SDL_Window* m_win;
    SDL_Renderer* m_rndr;

    SDL_Event m_e;
};


#endif //IMPROVISE_ADAPT_OVERCOME_GRAPHICS_H
