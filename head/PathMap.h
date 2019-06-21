#ifndef PATHMAP_H
#define PATHMAP_H

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include "GameMap.h"

using namespace std;

//crea una matrice di percorsi
class PathMap
{
private:
  vector<vector<pair<int, int> > > map;
  vector<pair<int, int> > currentPath;
  vector<ALLEGRO_COLOR> colors;
  GameMap gm;

public:  
  PathMap();
  GameMap& getLogic();
  void add(const int&, const int&, ALLEGRO_COLOR);
  void draw();
  vector<vector<pair<int, int> > > getPaths();
  pair<int, int> getLastCoords();
  bool isClosed(vector<pair<int,int> > ) const;
  bool victory() const;
};

#endif
