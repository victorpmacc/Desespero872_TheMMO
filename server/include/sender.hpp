#include "serverController.hpp"
#include <memory>
#include <thread>
#include <string>
#include <boost/asio.hpp>
#include <chrono>


void sender(std::shared_ptr<ServerController> serverController, int port);

