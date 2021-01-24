#include "gameController.hpp"
#include <iostream>

GameController::GameController(){
  this->stop = false;
}

nlohmann::json GameController::getStateJson(){
  nlohmann::json stateJson;
  nlohmann::json ballsJson;
  for (auto& ball: this->balls){
    ballsJson[ball.first] = ball.second.getStateJson();
  }
  stateJson["balls"] = ballsJson;
  std::cout<<stateJson<<std::endl;
  return stateJson;
}

void GameController::stopGame(){
  this->stop = true;
}

void GameController::saveStateJson(){
  this->stateWriteFile.open("state.json");
  stateWriteFile << this->getStateJson();
  stateWriteFile.close();
}

std::string GameController::addBall(std::string id){ // ogador ingame
  BallController b(100, 100, 100, 100);
  b.set_id(id);
  this->balls.insert(std::make_pair(b.get_id(), b));
  return b.get_id();
}

int GameController::deleteBall(std::string id){
  this->balls.erase(id);
  return this->balls.size();
}

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

void GameController::updateMovement(std::string id, int acao){
  this->balls.find(id)->second.addLine(acao);
}

int GameController::iterate(){

  for(auto &ball_atual: this->balls){
    ball_atual.second.iterate();
  }

  if(this->balls.empty()){
    return 0;
  }

  this->dumpedJson = this->getStateJson().dump();
  return this->stop;
}

std::string GameController::get_dumpedJson(){
  return this->dumpedJson;
}

GameController::~GameController(){} // def destrutora