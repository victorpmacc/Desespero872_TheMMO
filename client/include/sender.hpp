
#include "gameController.hpp"
#include "clientController.hpp"
#include <memory>
#include <thread>
#include <string>
#include <boost/asio.hpp>
#include <thread>
#include <chrono>
#include "json.hpp"

void sender(std::shared_ptr<ClientController> clientController);

