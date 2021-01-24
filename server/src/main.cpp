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
  std::shared_ptr<GameController> gameController = std::make_shared<GameController>();
  std::shared_ptr<ServerController> serverController = std::make_shared<ServerController>(gameController, 9001);
  
  // Duas threads operantes no server: envio e recebimento atuando simultaneamente
  std::thread thread_receiver = std::thread(receiver, serverController, 9001);
  std::thread thread_sender = std::thread(sender, serverController, 9001);

  gameController->start();
  
  thread_receiver.join();
  thread_sender.join();

  return 0;
};