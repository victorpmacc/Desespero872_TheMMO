#include "serverController.hpp"

ServerController::ServerController(std::shared_ptr<GameController> gameController, int port){
  this->gameController = gameController;
  
  boost::asio::io_service io_service;
  boost::asio::ip::udp::endpoint local_endpoint(boost::asio::ip::udp::v4(), port);

  this->socket = std::make_shared<boost::asio::ip::udp::socket>(io_service, local_endpoint);
}

void ServerController::pushToQueue(nlohmann::json requisition, boost::asio::ip::udp::endpoint client_endpoint){
	this->clientCommandStack.push(std::make_pair(requisition, client_endpoint));
}

std::pair<nlohmann::json, boost::asio::ip::udp::endpoint> ServerController::removeFromQueue(){
	std::pair<nlohmann::json, boost::asio::ip::udp::endpoint> front = this->clientCommandStack.front();
	this->clientCommandStack.pop();
	return front;
}

bool ServerController::isQueueEmpty(){
	return this->clientCommandStack.empty();
}

bool ServerController::isEndpointMapEmpty(){
	return this->endpointMap.empty();
}

std::unordered_map<std::string, boost::asio::ip::udp::endpoint> ServerController::get_endpointMap(){
	return this->endpointMap;
}

void ServerController::addEndpoint(boost::asio::ip::udp::endpoint new_endpoint){
	std::cout<<"Adicionando endpoint"<<std::endl;

	this->endpointMap.insert(std::make_pair(new_endpoint.address().to_string(), new_endpoint));
}

std::shared_ptr<GameController> ServerController::get_gameController(){
	return this->gameController;
}

std::shared_ptr<boost::asio::ip::udp::socket> ServerController::get_socket(){
	return this->socket;
}
