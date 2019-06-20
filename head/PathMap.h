#ifndef PATHMAP_H
#define PATHMAP_H

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include "Color.h"
#include "GameMap.h"

using namespace std;

//crea una matrice di percorsi
class PathMap
{
private:
  vector<vector<pair<int, int> > > map;
  vector<ALLEGRO_COLOR> colors;

public:  
  PathMap();
  void add(const int&, const int&, ALLEGRO_COLOR);
  pair<int, int> getLastCoords();
  bool isClosed(const GameMap&, vector<pair<int,int> > ) const;
  bool victory(const GameMap &gameMap) const;
};

#endif
