#include "ballView.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>

BallView::BallView(int height, int width){
  this->rect.height = height;
  this->rect.width = width;
}

void BallView::update(int posX, int posY){
  this->rect.posX = posX;
  this->rect.posY = posY; // no código dos meninos, aqui ta como ((x>0) interrogacao x:0)
}

void BallView::set_render(SDL_Renderer *renderer){
  this->renderer = renderer;
  this->texture = IMG_LoadTexture(renderer, './ball.png')
}

SDL_Renderer* BallView::get_render(){
  return this->renderer;
}

void BallView::draw(){
  SDLRenderCopy(renderer, this->texture, nullptr, &(this->rect));
}
