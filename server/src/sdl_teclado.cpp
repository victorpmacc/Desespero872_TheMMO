#include "sdl_teclado.hpp"

SDL_Keyboard::SDL_Keyboard(){
  state = SDL_GetKeyboardState(nullptr); // estado do teclado
}

int SDL_Keyboard::getInput(){
  SDL_PumpEvents();
  int ret = 0; // valor base para retorno, sem nada pressionado
  if(this->state[SDL_SCANCODE_ESCAPE]){
    ret |= (1<<KEYBOARD_ESC);
  }
  if(this->state[SDL_SCANCODE_LEFT]){
    ret |= (1<<KEYBOARD_LEFT);
  }
  if(this->state[SDL_SCANCODE_RIGHT]){
    ret |= (1<<KEYBOARD_RIGHT);
  }
  if(this->state[SDL_SCANCODE_UP]){
    ret |= (1<<KEYBOARD_UP);
  }
  if(this->state[SDL_SCANCODE_DOWN]){
    ret |= (1<<KEYBOARD_DOWN);
  }

  return ret;
}


