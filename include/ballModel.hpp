#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sdl_teclado.hpp"
#include "ballModel.hpp"
#include <memory>

#define PASSO 10

class BallModel{
  private:
    int posX, posY, height, width;
    SDL_Rect rect; // Conter os dados para renderização no SDL
  public:
    BallModel(int posX, int posY, int height, int width);
    void set_posX(int);
    int get_posX();
    void set_posY(int);
    int get_posY();

    void comandoTeclado(int);

    const SDL_Rect* get_rect(); // Passar pegar os dados para renderização no SDL

    //Falta adicionar o referente à passagem para o json. Referencia: bodyModel.hpp 31 e 32
};
