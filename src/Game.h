#include <SDL2/SDL.h>
#include <iostream>
#include "Config.h"

class Game {
  public:
    Game(Config cfg);
    ~Game();

    void init();
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    bool isRunning = false;

    Config config;
};