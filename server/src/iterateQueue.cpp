#include "iterateQueue.hpp"

void iterateQueue(std::shared_ptr<ServerController> serverController){
	static bool firstBall = true; //////
	std::pair<nlohmann::json, boost::asio::ip::udp::endpoint> currentPair;
	nlohmann::json clientJson;
	boost::asio::ip::udp::endpoint remote_endpoint;
	nlohmann::json response;
	while (!(serverController->get_gameController()->stop)){
		if (!(serverController->isQueueEmpty())){
			currentPair = serverController->removeFromQueue();
			
			clientJson = currentPair.first;
			remote_endpoint = currentPair.second;

			std::string request_type = clientJson["type"];
			
			if (request_type.compare("handshake") == 0) {
				std::string new_ball_id = serverController->get_gameController()->addBall(remote_endpoint.address().to_string());	
				response["type"] = "handshake";
				response["body"]["id"] = new_ball_id;
				serverController->addEndpoint(remote_endpoint);
				std::cout<<"Temos um handshake"<<std::endl;
				if (firstBall){
					firstBall = false;
				}
			} else if (request_type.compare("command") == 0){
				
				std::string id = remote_endpoint.address().to_string();
				int action = clientJson["body"]["comando"];

				serverController->get_gameController()->updateMovement(id, action);

			} else if (request_type.compare("goodbye") == 0){
				std::string id = remote_endpoint.address().to_string();
				int retRemove = serverController->get_gameController()->deleteBall(id);
				if (retRemove <= 0){
					serverController->get_gameController()->stopGame();
				}
			} else {
				std::cout<<"Tipo invalido! (handshake, command, goodbye)"<<std::endl;
			}
		}
	}

}
