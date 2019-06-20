#ifndef LEVEL_H
#define LEVEL_H

#include "GameMap.h"
#include "PathMap.h"
#include "GameEngine.h"

class Level:public GameEngine
{
private:
  GameMap myMap;
  PathMap myPaths;
  
  bool mouse_down = false;

  //nuovo parametro aggiunto gameMode
  //rimuoverlo e creare due classi figlie LevelMoves e LevelTimer
  int gameMode;

  GameObj* start = nullptr;
  GameObj* current = nullptr;
  GameObj* next = nullptr;
  GameObj* end = nullptr;

  vector<GameObj*> path_list;

  void redraw();
  void cursor(ALLEGRO_COLOR);
  void drawPath();

public:
  Level(int mode);
  void run(const char*);
  ~Level();

};
#endif
