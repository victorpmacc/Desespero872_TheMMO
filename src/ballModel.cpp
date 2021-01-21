#include "ballModel.hpp"

BallModel::BallModel(int posX, int posY, int height, int width){
  this->posX = posX;
  this->posY = posY;
  this->height = height;
  this->width = width;
  this->rect.x = posX;
  this->rect.y = posY;
  this->rect.h = height;
  this->rect.w = width;
}

void BallModel::set_posX(int nova_posX){
  this->posX = nova_posX;
  this->rect.x = this->posX;
}

int BallModel::get_posX(){
  return this->posX;
}

void BallModel::set_posY(int nova_posY){
  this->posY = nova_posY;
  this->rect.y = this->posY;
}

int BallModel::get_posY(){
  return this->posY;
}

const SDL_Rect* BallModel::get_rect(){
  return &(this->rect);
}

void BallModel::comandoTeclado(int entrada){
  if(entrada & (1 << KEYBOARD_UP)){
    this->set_posY(this->get_posY() - PASSO);
  }
  if(entrada & (1 << KEYBOARD_DOWN)){
    this->set_posY(this->get_posY() + PASSO);
  }
  if(entrada & (1 << KEYBOARD_LEFT)){
    this->set_posX(this->get_posX() - PASSO);
  }
  if(entrada & (1 << KEYBOARD_RIGHT)){
    this->set_posX(this->get_posX() + PASSO);
  }
}

// faltaria adicionar os baseJson- perguntar. Referencia: bodyModel.cpp 61 - fim E characterModel.cpp 44 - fim