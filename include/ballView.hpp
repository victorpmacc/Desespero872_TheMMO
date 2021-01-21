#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class BallView{
  private:
    int posX,posY;
    char* src_asset;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect rect;
  public:
    //Construtor:
    BallView(int height, int width, const char* src_asset);
    //Aualiza a textura mostrada na tela (posicao):
    void update(int posX, int posY);
    //Seta o render do jogo:
    void set_render(SDL_Renderer *renderer);
    SDL_Renderer *get_render();
    
    void draw();
};
