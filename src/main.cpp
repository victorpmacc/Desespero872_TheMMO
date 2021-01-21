#include "ballController.hpp"
#include "gameController.hpp"
#include "gameView.hpp"
// #include "clientController.hpp"
// #include "sender.hpp"
// #include "receiver.hpp"
#include <vector>
#include <string>
//#include <boost/asio.hpp>

int main(){
  std::shared_ptr<GameController> gameController = std::make_shared<GameController>();
  //std::shared_ptr<ClientController> clientController = std::make_shared<ClientController>(gameController, FILENAME_STATE_INIT)

  //clientController->makeHandshake();

  //std::thread thread_receiver = std::thread(receiver, clientController);
  //std::thread thread_sender = std::thread(sender, clientController);

  gameController->start();
  
  //thread_receiver.join();
  //thread_sender.join();

  return 0;

};