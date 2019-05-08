#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GameObj.h"
#include "Ball.h"
#include "Path.h"
#include "Empty.h"
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

  void add(GameObj*&, const int&, const int&);
  void remove(const int&, const int&);

  int get(const int&)const;
  GameObj* getObj(const int&, const int&)const;
  bool inMap(const int&, const int&)const;

  unsigned getColors()const;
  bool isFull()const;

};

#endif
