#include "GameMap.h"
#include <iostream>

#ifndef LEVEL_H
#define LEVEL_H

class Level
{
private:
  GameMap myMap;
  const unsigned x = 20;
  const unsigned y = 20;

public:
  Level();
  void run(const char*);
  ~Level();
};
#endif
