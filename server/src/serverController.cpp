#include "clientController.hpp"

ClientController::ClientController(std::shared_ptr<GameController> gameController, std::string filename){
  this->gameController = gameController;
  std::fstream stateReadFile(filename, std::ios_base::in);
  std::string ip;
  std::getline(stateReadFile, ip);
  int port;
  stateReadFile >> port;

  boost::asio::io_service io_service;
  boost::asio::ip::udp::endpoint local_endpoint(boost::asio::ip::udp::v4(), port);

  this->socket = std::make_shared<boost::asio::ip::udp::socket>(io_service, local_endpoint);
  this->endpoint = std::make_shared<boost::asio::ip::udp::endpoint>( boost::asio::ip::address::from_string(ip), port);
}

void ClientController::makeHandshake(){
  nlohmann::json request;
  request["type"] = "handshake";
  this->socket->send_to(boost::asio::buffer(request.dump()), *this->endpoint);
}

std::shared_ptr<GameController> ClientController::get_gameController(){
  return this->gameController;
}

std::shared_ptr<boost::asio::ip::udp::socket> ClientController::get_socket(){
  return this->socket;
}

std::shared_ptr<boost::asio::ip::udp::endpoint> ClientController::get_endpoint(){
  return this->endpoint;
}