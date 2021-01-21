#include "ballView.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>

BallView::BallView(int height, int width, const char* src_asset){
  this->rect.h = height;
  this->rect.w = width;
  this->src_asset = (char*) malloc(sizeof(char)*(strlen(src_asset)+1));
  std::strcpy(this->src_asset, src_asset);
}

void BallView::update(int posX, int posY){
  this->rect.x = posX;
  this->rect.y = posY; // no código dos meninos, aqui ta como ((x>0) interrogacao x:0)
}

void BallView::set_render(SDL_Renderer *renderer){
  this->renderer = renderer;
  this->texture = IMG_LoadTexture(renderer, src_asset);
}

SDL_Renderer* BallView::get_render(){
  return this->renderer;
}

void BallView::draw(){
  SDL_RenderCopy(renderer, this->texture, nullptr, &(this->rect));
}
