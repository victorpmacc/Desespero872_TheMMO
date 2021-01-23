#include "ballController.hpp"
#include "gameController.hpp"
#include "serverController.hpp"
#include "sender.hpp"
#include "receiver.hpp"
#include "iterateQueue.hpp"
#include <vector>
#include <string>
#include <boost/asio.hpp>

int main(int argc, char *argv[]){
  std::shared_ptr<GameController> gameController = std::make_shared<GameController>(); //cria GameController
  std::shared_ptr<ClientController> clientController = std::make_shared<ClientController>(gameController, "../state.ini"); //cria ClientController; state.ini - container
  
  clientController->makeHandshake();

  // Duas threads operantes no client: envio e recebimento atuando simultaneamente
  std::thread thread_receiver = std::thread(receiver, clientController);
  std::thread thread_sender = std::thread(sender, clientController);

  gameController->start();
  
  thread_receiver.join();
  thread_sender.join();

  return 0;

};