#pragma once

#include <queue>
#include "gameController.hpp"
#include "json.hpp"
#include <memory>
#include <utility>
#include <map>
#include <vector>
#include <boost/asio.hpp>

class ServerController {
	private:
		std::queue<
			std::pair<nlohmann::json, boost::asio::ip::udp::endpoint>
			> clientCommandStack;
		std::shared_ptr<GameController> gameController;
		std::unordered_map<std::string, boost::asio::ip::udp::endpoint> endpointMap;
		std::shared_ptr<boost::asio::ip::udp::socket> socket;

	public:

		ServerController(std::shared_ptr<GameController> gameController, int port);
		std::pair<nlohmann::json, boost::asio::ip::udp::endpoint> removeFromQueue();
		void pushToQueue(nlohmann::json requisition, boost::asio::ip::udp::endpoint client_endpoint);
	     	bool isQueueEmpty();
		bool isEndpointMapEmpty();
		void addEndpoint(boost::asio::ip::udp::endpoint new_endpoint);
		std::unordered_map<std::string, boost::asio::ip::udp::endpoint> get_endpointMap();
		std::shared_ptr<GameController> get_gameController();
		void send_to(std::string message, boost::asio::ip::udp::endpoint remote_endpoint);
		void receive_from(char message[], int size, boost::asio::ip::udp::endpoint remote_endpoint);	
		std::shared_ptr<boost::asio::ip::udp::socket> get_socket();
};
