#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GameObj.h"
#include <fstream>

//crea una matrice di oggetti (palline o percorsi)
class GameMap
{
private:
  const unsigned n = 5;
  GameObj*** map;
  char** levelmap;
  unsigned x, y;

  void readLevel(const char*);

public:
  GameMap();
  
  void draw(const unsigned &, const unsigned &, const char*);

 ~GameMap();
  

  unsigned size()const;

  //GameObj* getObj(const unsigned &, const unsigned &);

  unsigned getColors()const;

  bool isFull()const;

};

#endif
