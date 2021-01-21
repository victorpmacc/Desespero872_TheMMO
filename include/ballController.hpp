#pragma once
#include "ballModel.hpp"
#include "ballView.hpp"
#include "sdl_teclado.hpp"
// #include "json.hpp"

#include <utility>

class BallController{
  private:
    std::shared_ptr<BallModel> ballModel;
    std::shared_ptr<BallView> ballView;
    SDL_Keyboard keyboard;

  public:
    BallController(int poX, int posY, int height, int width);
    void updateView();
    //void updateModel(); -> eu quem tirei, aparentemente nao se usa esse. Pode ser removido
    std::shared_ptr<BallModel> getModel();
    std::shared_ptr<BallView> getView();
    void iterate();
    //json, ref characterController.hpp 26 - fim
};
