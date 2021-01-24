#include "ballController.hpp"

BallController::BallController(int posX, int posY, int height, int width){
  this->ballModel = std::shared_ptr<BallModel>(new BallModel(posX, posY, height, width));
  std::cout<<"Nova ball ingame"<<std::endl;
  std::queue<int> line;
}

void BallController::updateModel(){
  while((line.size())> 0){
    this->ballModel->comandoTeclado(line.front());
  }
}

std::shared_ptr<BallModel> BallController::getModel(){
  return this->ballModel;
}

void BallController::iterate(){
  this->updateModel();
}

nlohmann::json BallController::getStateJson(){
  nlohmann::json stateJson;
  stateJson["model"] = this->ballModel->getStateJson();
  return stateJson;
}

std::string BallController::get_id(){
  return this->id;
}

void BallController::set_id(std::string id){
  this->id = id;
}

void BallController::addLine(int acao){
  this->line.push(acao);
}