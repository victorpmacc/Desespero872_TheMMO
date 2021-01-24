#pragma once
#include "ballModel.hpp"
#include "sdl_teclado.hpp"
#include "json.hpp"
#include <queue>
#include <map>
#include <utility>

class BallController{
  private:
    std::shared_ptr<BallModel> ballModel;
    std::string id;
    std::queue<int> line;

  public:
    BallController(int poX, int posY, int height, int width);
    void updateModel();
    std::shared_ptr<BallModel> getModel();
    void iterate();
    nlohmann::json getStateJson();
    void readStateJson(nlohmann::json state);
    std::string get_id();
    void set_id(std::string id);
    void addLine(int acao);
};
