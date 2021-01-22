#pragma once

#include "gameView.hpp"
#include "ballController.hpp"
#include "sdl_teclado.hpp"
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
#include <unordered_map>

class GameController{
  private:
    std::unique_ptr<GameView> gameView; // ref classe GameView

    std::unordered_map<std::string, BallController> balls;
    void updateBallView();

    SDL_Keyboard keyboard; // contem state do teclado para ser pego com o getInput()
    
    int action;

    std::shared_ptr<BallView> ball;
  public:
    GameController(); // criadora
    ~GameController(); // destrutora

    void start();
    int iterate();
    int get_action();
    //nlohmann::json getStateJson();
    //void readStateJson();
    //void saveStateJson();
    //void readServerStateJson(nlohmann::json stateJson); ref gameController.hpp 48

    bool stop; //por que tá como public e nao private interrogação
};
