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

nlohmann::json BallModel::baseJson(){ //coloca no json
  nlohmann::json base;
  base["x"] = this->posX;
  base["y"] = this->posY;
  base["h"] = this->height;
  base["w"] = this->width;
  return base;
}

void BallModel::readBaseJson(nlohmann::json base){ //le json e pega
  this->posX = base["x"];
  this->posY = base["y"];
  this->rect.h = base["h"];
  this->rect.w = base["w"];
}

nlohmann::json BallModel::getStateJson(){
  nlohmann::json stateJson;
  stateJson["base"] = this->baseJson(); // nao faz nada além de chamar baseJson para stateJson["base"]
  return stateJson;
}

void BallModel::readStateJson(nlohmann::json state){
  this->readBaseJson(state["base"]); // nao faz nada além de chamar read base json para state["base"]
}


void BallModel::comandoTeclado(int entrada){
  if(entrada & (1 << KEYBOARD_UP)){
    this->set_posY(this->get_posY() - 10);
  }
  if(entrada & (1 << KEYBOARD_DOWN)){
    this->set_posY(this->get_posY() + 10);
  }
  if(entrada & (1 << KEYBOARD_LEFT)){
    this->set_posX(this->get_posX() - 10);
  }
  if(entrada & (1 << KEYBOARD_RIGHT)){
    this->set_posX(this->get_posX() + 10);
  }
}