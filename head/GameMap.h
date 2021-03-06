#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GameObj.h"
#include "Ball.h"
#include "Path.h"
#include "Empty.h"
#include <fstream>
#include <vector>
#include <algorithm>

//crea una matrice logica di oggetti (palline o percorsi)
class GameMap
{
private:
  const unsigned n = 5;

  vector<vector<GameObj*> > map;
  vector<vector<char> > levelmap;
  
  void readLevel(const int&);

public:  
  GameMap();
  void load(const int&);
  unsigned size()const;
 ~GameMap();
  unsigned getColors()const;

  void addPath(const int&, const int&, ALLEGRO_COLOR);
  void removePath(const int&, const int&);
  void clearPath();

  int get(const int&)const;

  GameObj* getObj(const int&, const int&)const;
  GameObj* getLogicObj(const int&, const int&)const;
  bool inMap(const int&, const int&)const;

  bool isFull()const;

};

#endif
