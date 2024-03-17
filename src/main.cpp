#include "Game.h"
#include "Config.h"

int main(int argc, char *argv[]) {
  // absolute path to be safe
  Config cfg = Config::readConfig("/home/blake/Documents/github.com/blakesekelsky/example-gameini/game.ini");
  Game *game = new Game(cfg);

  const int frameDelay = 1000 / cfg.fpsmax;
  uint32_t frameStart;
  int frameTime;

  game->init();
  while (game->running()) {
    frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();

    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  game->clean();
  return 0;
}