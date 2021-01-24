#include "serverController.hpp"
#include <thread>
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <memory>

void receiver(std::shared_ptr<ServerController> serverController, int port);
