#ifndef VICTORY_H
#define VICTORY_H

#include "GameMap.h"

void victoryScreen(const GameMap &mp, const GameMap &mb)
{
  if(mp.isFull() && mb.isFull() && mb.getColors() == mp.getColors())
  {
    //schermata di vittoria
  }
}
#endif
