#include "ballController.hpp"

BallController::BallController(int posX, int posY, int height, int width){
  this->ballView = std::shared_ptr<BallView>(new BallView(height, width));
  this->ballModel = std::shared_ptr<BallModel>(new BallModel(posX, posY, height, width));
}

void BallController::updateView(){
  this->ballView->update(this->ballModel->get_posX(), this->ballModel->get_posY());
  this->ballView->draw();
}

std::shared_ptr<BallView> BallController::getView(){
  return this->ballView;
}

std::shared_ptr<BallModel> BallController::getModel(){
  return this->ballModel;
}

void BallController::iterate(){
  this->updateView();
}

nlohmann::json BallController::getStateJson(){
  nlohmann::json stateJson;
  return stateJson;
}

void BallController::readStateJson(nlohmann::json stateJson){
  this->ballModel->readStateJson(stateJson["model"]);
}