#pragma once

#include "gameView.hpp"
#include "ballController.hpp"
#include "sdl_teclado.hpp"
// #include "gameModel.cpp" -> NAO temos game model
//#include "json.cpp"
#include <iostream>
#include <map>
#include <chrono>
#include <iomanip>
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>
#include <boost/asio.hpp>
#include <thread>

class GameController{
  private:
    //std::unique_ptr<GameModel> gameModel; -> NAO temos game model
    std::unique_ptr<GameView> gameView; // ref classe GameView

    //std::unordered_map<std::string, ballController> ball;
    std::unique_ptr<BallController> ball; //criado por mim. Nao sei se é assim, imagino  o map tá para quando usa o json
    void updateBallView();

    SDL_Keyboard keyboard; // contem state do teclado para ser pego com o getInput()
    
    int action;

  public:
    GameController(); // criadora
    ~GameController(); // destrutora

    void start();
    int iterate();
    int get_action();
    //nlohmann::json getStateJson();
    //void readStateJson();
    //void saveStateJson();
    //void readServerStateJson(nlohmann::json stateJson);

    bool stop; //por que tá como public e nao private interrogação
}