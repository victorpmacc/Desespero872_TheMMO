#include "sender.hpp"

void sender(std::shared_ptr<ClientController> clientController){
  static auto t_start = std::chrono::high_resolution_clock::now();
  static auto t_end = std::chrono::high_resolution_clock::now();
  while(!clientController->get_gameController()->stop){ //enquanto rola

    int action = clientController->get_gameController()->get_action();
    nlohmann::json request;
    request["type"] = "command";
    request["body"]["id"] = action;
    clientController->get_socket()->send_to(boost::asio::buffer(request.dump()), *clientController->get_endpoint());
    std::cout << "Client Enviando..." << std::endl;

    t_end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
    if(elapsed < 40){
      std::this_thread::sleep_for(std::chrono::milliseconds(40 - elapsed));
    }

    t_start = t_end;
  }
  std::cout << "Encerrando..." << std::endl;
} 
