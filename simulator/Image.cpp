//
// Created by mathis on 07/12/22.
//

#include "Image.h"

Image::Image(SDL_Renderer* rndr, std::string path, int x, int y, int w, int h) {
    m_img_surf = IMG_Load(path.c_str());

    if(!m_img_surf) {
        std::cout << "ERROR: Failed to load " << path << std::endl;
    }

    m_img = SDL_CreateTextureFromSurface(rndr, m_img_surf);

    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
}

Image::~Image() {

}

void Image::Render(SDL_Renderer* rndr) {
    SDL_Rect r{};
    r.x = m_x;
    r.y = m_y;
    r.w = m_w;
    r.h = m_h;

    SDL_RenderCopyEx(rndr, m_img, nullptr, &r, 0.0, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
}

void Image::SetPos(int x, int y) {
    m_x = x;
    m_y = y;
}

void Image::SetScale(int w, int h) {
    m_w = w;
    m_h = h;
}

Color Image::GetPixel(int x, int y) {
    if(x < 0 || y < 0) {
        return {0, 0, 0, 0};
    }

    std::array<uint8_t, 4> PixelData{0};
    size_t bpp = m_img_surf->format->BytesPerPixel;

    for(int i = 0; i < bpp; i++) {
        int p = m_img_surf->pitch;
        uint8_t partial_pixel = ((uint8_t*)m_img_surf->pixels)[(y * p) + (x * bpp) + i];
        PixelData[i] = partial_pixel;
    }

    return {PixelData[0], PixelData[1], PixelData[2], PixelData[3]};
}