#include "gameController.hpp"
#include <thread>
#include <string>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "clientController.hpp"
#include <memory>

void receiver(std::shared_ptr<ClientController> clientController);
