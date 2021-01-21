#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

typedef enum{
  KEYBOARD_UP=1,
  KEYBOARD_DOWN,
  KEYBOARD_LEFT,
  KEYBOARD_RIGHT,
  KEYBOARD_ESC
} KeyboardTeclas; // será utilizado para computar ações do teclado bitwise, permitindo duas direções ao mesmo tempo

class SDL_Keyboard{
  private:
    const Unit8* state;
  public:
    SDL_Keyboard(); // seta o state para receber dados do teclado
    int getInput(); // retorna info do teclado, bitwise, de acordo com a enumeração em KeyboardTeclas
}