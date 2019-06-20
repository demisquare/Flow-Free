#ifndef PATHMAP_H
#define PATHMAP_H

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include "Color.h"

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
  pair<int, int> getLastCoords(){return map.back().back();}
};

#endif
