#include "receiver.hpp"

void receiver(std::shared_ptr<ServerController> serverController, int port){
  char clean[10000]; // vetor limpo para 'zerar' v
  int i;
  for(i=0; i<10000; i++){
    clean[i]='\0';
  }
  char v[10000];

  bool firstBall = true;
  while (!(serverController->get_gameController()->stop)){
    memcpy(v, clean, 10000);

    boost::asio::ip::udp::endpoint remote_endpoint;
    serverController->get_socket()->receive_from(boost::asio::buffer(v, 10000), remote_endpoint);
    nlohmann::json clientJson = nlohmann::json::parse(v);
    std::string request_type = clientJson["type"];

    std::cout<<clientJson<<std::endl;

    if(request_type.compare("handshake") == 0){

      std::string new_ball_id = serverController->get_gameController()->addBall(remote_endpoint.address().to_string());
      serverController->addEndpoint(remote_endpoint);
      std::cout<<"Handshake Done"<<std::endl;
      if(firstBall){
        firstBall = false;
      }

    } else if(request_type.compare("command") == 0){

      std::string id = remote_endpoint.address().to_string();
      int action = clientJson["body"]["comando"];
      std::cout<<"Pedido de acao"<<std::endl;
      serverController->get_gameController()->updateMovement(id, action);
      std::cout<<"Acao done"<<std::endl;


    } else if(request_type.compare("goodbye") == 0){

      std::string id = remote_endpoint.address().to_string();
      int retRemove = serverController->get_gameController()->deleteBall(id);
      if(retRemove <= 0){
        serverController->get_gameController()->stopGame();
      }
    } else{
      std::cout<<"Tipo invalido! (handshake, command, goodbye) [case-sensitive]"<<std::endl; // Pode ser tirado se estiver tudo ok
    }
  }
}