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
  ALLEGRO_BITMAP* buffer;

  //nuovo parametro aggiunto gameMode
  //rimuoverlo e creare due classi figlie LevelMoves e LevelTimer
  int gameMode;

  const unsigned x = 20, y = 20;

public:
  Level(ALLEGRO_BITMAP* b, int mode);
  void run(const char*);
  ~Level();

};
#endif
