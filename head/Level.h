#ifndef LEVEL_H
#define LEVEL_H

#include "PathMap.h"
#include "GameEngine.h"

class Level:public GameEngine
{
private:
  PathMap map;
  
  bool mouse_down = false;
  bool moved = false;

  int gameMode;
  int level;

  GameObj* start = nullptr;
  GameObj* current = nullptr;
  GameObj* end = nullptr;

  Score score;
  
  unsigned counter = 0;

  void redraw();
  void drawPath();

  int victory();
  int lose();
  
public:
  Level(int mode);
  int run(const int&);
  ~Level();

};
#endif
