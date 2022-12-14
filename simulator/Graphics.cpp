//
// Created by mathis on 07/12/22.
//

#include "Graphics.h"

Graphics::Graphics() {
    m_win = nullptr;
    m_e = {};
}

Graphics::~Graphics() {
    SDL_DestroyRenderer(m_rndr);
    SDL_DestroyWindow(m_win);
}

bool Graphics::Init(int w, int h, std::string title) {
    SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    m_win = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);

    if(!m_win) {
        return false;
    }

    m_rndr = SDL_CreateRenderer(m_win, 0, SDL_RENDERER_ACCELERATED);
    if(!m_rndr) {
        return false;
    }

    return true;
}

void Graphics::Update() {
    SDL_PollEvent(&m_e);

    SDL_SetRenderDrawColor(m_rndr, 0, 0, 0, 255);
    SDL_RenderClear(m_rndr);
}

void Graphics::EndFrame() {
    SDL_RenderPresent(m_rndr);
}

bool Graphics::WantToClose() {
    if(m_e.type == SDL_QUIT) {
        return true;
    }

    return false;
}