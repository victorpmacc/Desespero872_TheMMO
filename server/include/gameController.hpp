#pragma once

#include "ballController.hpp"
#include "sdl_teclado.hpp"
#include "json.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
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
    std::map<std::string, BallController> balls;
    std::ofstream stateWriteFile;
    std::stringstream stateReadFile;
    std::string dumpedJson;

  public:
    GameController(); // criadora
    ~GameController(); // destrutora

    void updateMovement(std::string id, int acao);
    std::string addBall(std::string id);
    int deleteBall(std::string id);
    void start();
    int iterate();
    nlohmann::json getStateJson();
    void saveStateJson();
    std::string get_dumpedJson();
    void stopGame();
    bool stop; //por que tá como public e nao private interrogação
};
