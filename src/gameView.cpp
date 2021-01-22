#include "gameView.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

GameView::GameView(){
  // Inicializando o subsistema de video do SDL
  if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
    std::cout << SDL_GetError();
    return;
  }

  // Criando uma janela
  window = nullptr;
  window = SDL_CreateWindow("DESESPERO 872 - THE OFFICIAL BALL GAME",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN);
  if (window==nullptr) { // Em caso de erro...
    std::cout << SDL_GetError();
    SDL_Quit();
    return;
  }

  // Inicializando o renderizador
  renderer = nullptr;
  renderer = SDL_CreateRenderer(
      window, -1,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  
  this->setBackground();
  if (renderer==nullptr) { // Em caso de erro...
    SDL_DestroyWindow(window);
    std::cout << SDL_GetError();
    SDL_Quit();
    return;
  }
}

void GameView::addBall(std::shared_ptr<BallView> ball){
  ball->set_render(renderer);
}

void GameView::setBackground(){
  background = IMG_LoadTexture(renderer, "../assets/campo.jpg");
}

void GameView::drawBackground(){
  SDL_RenderCopy(renderer, background, nullptr, nullptr);
}

int GameView::draw(){
  SDL_PumpEvents();
  while(SDL_PollEvent(&(this->event))){
    if (this->event.type == SDL_QUIT){
      return -1; // para
    }
  }
  SDL_RenderClear(this->renderer);

  this->drawBackground();

  return 0;
}

void GameView::finishDraw(){
  SDL_RenderPresent(this->renderer);
  SDL_Delay(30);
}

GameView::~GameView(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_DestroyTexture(background);
  SDL_Quit();
}