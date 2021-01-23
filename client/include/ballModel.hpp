#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sdl_teclado.hpp"
#include "ballModel.hpp"
#include "json.hpp"
#include <memory>

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

    void comandoTeclado(int); // no codigo dos meninos, retorna um Retorno Handle, que diz se o personagem ta default ou ta na animacao do machado, aqui e desnecessario o retorno (portanto void)

    const SDL_Rect* get_rect(); // Passar pegar os dados para renderização no SDL

    nlohmann::json baseJson();
    void readBaseJson(nlohmann::json base);
    nlohmann::json getStateJson(); // nao faz nada mais que pegar o baseJson, talvez possa ser removido
    void readStateJson(nlohmann::json state);// nao faz nada mais que chamar o baseJson, talvez possa ser removido
};
