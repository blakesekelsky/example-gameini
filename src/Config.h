#ifndef CONFIG_H
#define CONFIG_H

#include <SDL2/SDL.h>
#include <fstream>
#include <iostream>

struct Config {
  const char *title = "My game"; // this is hardcoded, but could be read from a config file if you don't initialize it here
  int startx = SDL_WINDOWPOS_CENTERED;
  int starty = SDL_WINDOWPOS_CENTERED;
  int width = 640;
  int height = 480;
  int fullscreen = 0;
  int fpsmax = 60;

  static Config readConfig(std::string filename) {
    Config cfg;

    std::ifstream file;
    file.open(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
          // if the line contains the key, and doesn't contain a semicolon, then it's a valid line
          if (line.find("startx") != std::string::npos && line.find(";") == std::string::npos) {
              cfg.startx = std::stoi(line.substr(line.find("=") + 1));
          } else if (line.find("starty") != std::string::npos && line.find(";") == std::string::npos) {
              cfg.starty = std::stoi(line.substr(line.find("=") + 1));
          } else if (line.find("width") != std::string::npos && line.find(";") == std::string::npos) {
              cfg.width = std::stoi(line.substr(line.find("=") + 1));
          } else if (line.find("height") != std::string::npos && line.find(";") == std::string::npos) {
              cfg.height = std::stoi(line.substr(line.find("=") + 1));
          } else if (line.find("fpsmax") != std::string::npos && line.find(";") == std::string::npos) {
              cfg.fpsmax = std::stoi(line.substr(line.find("=") + 1));
          } else if (line.find("fullscreen") != std::string::npos && line.find(";") == std::string::npos) {
              cfg.fullscreen = std::stoi(line.substr(line.find("=") + 1));
          }
        }
    } else { 
      printf("Failed to open file, resolving to default config\n");
      return cfg;
    }

    file.close();
    printf("Config read\n");
    return cfg;
  }
};

#endif