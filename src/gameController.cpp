#include "gameController.hpp"
#include <iostream>

GameController::GameController(){
  this->gameView = std::unique_ptr<GameView> (new GameView()); 
  this->keyboard = SDL_Keyboard();
  this->stop = false;
}

//void GameController::readServerStateJson(nlohmann::json stateJson){}

void GameController::start(){
  static auto t_start = std::chrono::high_resolution_clock::now();
  static auto t_end = std::chrono::high_resolution_clock::now();

  while(!(this->iterate())){
    t_end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count(); // conta tempo do frame do loop do game

    if (elapsed < 40){ //40ms/frame => 25frames/s
      std::this_thread::sleep_for(std::chrono::milliseconds(40 - elapsed));
    } 
    t_start = t_end;
  }
  this->stop = true;
}


int GameController::iterate(){
  int returnDraw = this->gameView->draw();

  for(auto &ball: this->balls){
    ball.second.updateView(); // Chama a atualização do View no ballController. 
  }

  this->gameView->finishDraw();
  this->action = this->keyboard.getInput(); // pega o status do teclado
  if (this->action & (1 << KEYBOARD_ESC)){
    return -1;
  }

  return returnDraw;
}

int GameController::get_action(){
  return this->action;
}

GameController::~GameController(){} // def destrutora