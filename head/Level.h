<<<<<<< HEAD
#include "GameMap.h"
#include <iostream>

#ifndef LEVEL_H
#define LEVEL_H

=======
#ifndef LEVEL_H
#define LEVEL_H

#include "GameMap.h"
#include "Setup.h"

>>>>>>> master
class Level
{
private:
  GameMap myMap;
<<<<<<< HEAD
  const unsigned x = 20;
  const unsigned y = 20;

public:
  Level();
  void run(const char*);
  ~Level();
=======
  ALLEGRO_TIMER* timer;
  ALLEGRO_EVENT_QUEUE* event_queue;
  ALLEGRO_BITMAP* buffer;

  int scaleX, scaleY;

  const unsigned x = 20, y = 20;

public:
  Level(ALLEGRO_BITMAP* b, int x, int y);
  void run(const char*);
  ~Level();

>>>>>>> master
};
#endif
