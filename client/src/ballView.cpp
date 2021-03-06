#include "ballView.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>

BallView::BallView(int height, int width){
  this->rect.h = height;
  this->rect.w = width;
}

void BallView::update(int posX, int posY){
  this->rect.x = posX;
  this->rect.y = posY; // no código dos meninos da arvore, aqui ta como ((x>0) interrogacao x:0)
}

void BallView::set_render(SDL_Renderer *renderer){
  this->renderer = renderer;
  this->texture = IMG_LoadTexture(renderer, "../assets/ball.png");
}

SDL_Renderer* BallView::get_render(){
  return this->renderer;
}

void BallView::draw(){
  SDL_RenderCopy(renderer, this->texture, nullptr, &(this->rect));
}
