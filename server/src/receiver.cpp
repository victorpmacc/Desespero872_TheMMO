#include "receiver.hpp"

void receiver(std::shared_ptr<ClientController> clientController){
  char clean[10000]; // vetor limpo para 'zerar' v
  int i;
  for(i=0; i<10000; i++){
    clean[i]='\0';
  }
  char v[10000];

  while (!(clientController->get_gameController()->stop)){
    memcpy(v, clean, 10000);

    std::cout << "Esperando mensagem!" << std::endl; //repetidamente recebendo

    if(!(clientController->get_gameController()->stop)){
      clientController->get_socket()->receive_from(boost::asio::buffer(v, 10000), *clientController->get_endpoint()); // recebe local e endpoint
      std::cout << "Fim da mensagem!" << std::endl;
      clientController->get_gameController()->readServerStateJson(nlohmann::json::parse(v));
    }
    memcpy(v, clean, 10000);
  }
}