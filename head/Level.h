#ifndef LEVEL_H
#define LEVEL_H

#include "GameMap.h"
#include "Setup.h"

class Level
{
private:
  GameMap myMap;
  ALLEGRO_TIMER* timer;
  ALLEGRO_EVENT_QUEUE* event_queue;

  const unsigned x = 20, y = 20;

public:
  Level();
  void run(const char* lvl);
  ~Level();

};
#endif
