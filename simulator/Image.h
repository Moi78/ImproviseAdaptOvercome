//
// Created by mathis on 07/12/22.
//

#ifndef IMPROVISE_ADAPT_OVERCOME_IMAGE_H
#define IMPROVISE_ADAPT_OVERCOME_IMAGE_H

#include <iostream>
#include <string>
#include <array>
#include <cstdint>

#include <SDL.h>
#include <SDL_image.h>

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

class Image {
public:
    Image(SDL_Renderer* rndr, std::string path, int x, int y, int w, int h);
    ~Image();

    void Render(SDL_Renderer* rndr);

    void SetPos(int x, int y);
    void SetScale(int w, int h);

    Color GetPixel(int x, int y);

private:
    SDL_Surface* m_img_surf;
    SDL_Texture* m_img;

    int m_x, m_y;
    int m_w, m_h;

    int m_im_w, m_im_h;

};


#endif //IMPROVISE_ADAPT_OVERCOME_IMAGE_H
