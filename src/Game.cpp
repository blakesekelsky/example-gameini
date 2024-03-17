#include "Game.h"
#include <iostream>

Game::Game(Config cfg) : config(cfg) {
  window = nullptr;
  renderer = nullptr;
  isRunning = false;
}
Game::~Game() {}

void Game::init() {
  int flags = 0;
  
  if (config.fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    printf("SDL initialized\n");
    
    window = SDL_CreateWindow(config.title, config.startx, config.starty, config.width, config.height, flags);
    if (window) {
      printf("Window created\n");
    } else {
      printf("Window failed to create\n");
      isRunning = false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      printf("Renderer created\n");
      isRunning = true;
    } else {
      printf("Renderer failed to create\n");
      isRunning = false;
    }
  } else {
    printf("SDL init failed\n");
  }
}

void Game::handleEvents() {
  SDL_PollEvent(&event);

  // quit on window close
  switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;
    default:
      break;
  }

  // quit on escape key
  switch (event.key.keysym.sym) {
    case SDLK_ESCAPE:
      isRunning = false;
      break;
    default:
      break;
  }
}

void Game::update() {
  // update game objects
}

void Game::render() {
  SDL_RenderClear(renderer);
  
  // render game objects
  
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  printf("Game cleaned\n");
}