#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iomanip>
#include <iostream>
#include "ballView.hpp"
#include <memory>
#include <vector>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class GameView{
  private:
    SDL_Texture *background;
    SDL_Window *window;
    SDL_Renderer* renderer;
    SDL_Event event;
  public:
    GameView();
    ~GameView();
    int draw();
    void finishDraw();
    void setBackground();
    void addBall(std::shared_ptr<BallView> ball);
    void drawBackground();
};
