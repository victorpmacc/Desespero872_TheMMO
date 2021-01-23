#pragma once

#include "gameController.hpp"
#include "json.hpp"
#include <memory>
#include <boost/asio.hpp>

class ClientController {
	private:
		std::shared_ptr<boost::asio::ip::udp::socket> socket;
		std::shared_ptr<boost::asio::ip::udp::endpoint> endpoint;
		std::shared_ptr<GameController> gameController;
	public: 
		ClientController(std::shared_ptr<GameController> gameController, std::string filename);
		void makeHandshake();
		std::shared_ptr<GameController> get_gameController(); 
		std::shared_ptr<boost::asio::ip::udp::socket> get_socket();
		std::shared_ptr<boost::asio::ip::udp::endpoint> get_endpoint();
};
