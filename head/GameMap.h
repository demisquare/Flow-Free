#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GameObj.h"
#include "Ball.h"
#include "Path.h"
#include <fstream>

//crea una matrice di oggetti (palline o percorsi)
class GameMap
{
private:
  const unsigned n = 5;
  const unsigned pos = 90;
  const unsigned offset = 140;
  const unsigned r = 65;

  GameObj*** map;
  char** levelmap;
  unsigned x, y;

  void readLevel(const char*);

public:
  GameMap();
  
  void load(const char*);
  void draw(const unsigned &, const unsigned &);
 ~GameMap();
  unsigned size()const;

  string getCoordinates(const int&, const int&);

  unsigned getColors()const;
  bool isFull()const;

};

#endif
