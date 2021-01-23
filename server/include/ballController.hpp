#pragma once
#include "ballModel.hpp"
#include "ballView.hpp"
#include "sdl_teclado.hpp"
#include "json.hpp"

#include <utility>

class BallController{
  private:
    std::shared_ptr<BallModel> ballModel;
    std::shared_ptr<BallView> ballView;
    SDL_Keyboard keyboard;

  public:
    BallController(int poX, int posY, int height, int width);
    void updateView();
    std::shared_ptr<BallModel> getModel();
    std::shared_ptr<BallView> getView();
    void iterate();
    nlohmann::json getStateJson();
    void readStateJson(nlohmann::json state);
};
