#ifndef PATHMAP_H
#define PATHMAP_H

#include <utility>
#include <iostream>
#include "GameMap.h"
#include <cmath>

//crea e gestisce una matrice di percorsi...
class PathMap
{
private:
  vector<vector<pair<int, int> > > map;
  vector<pair<int, int> > currentPath;
  vector<ALLEGRO_COLOR> colors;
  GameMap gm;

  vector<pair<int, int> > findPath(pair<int, int>);
  bool adj(pair<int, int>);
  bool isClosed(vector<pair<int,int> >);
  bool isSigned(pair<int, int>);
  bool isUnique();

  void shrink(pair<int, int>);

public:  
  GameMap& getLogic();
  void load(const int&);
  bool add(const int&, const int&, ALLEGRO_COLOR);
  bool removePath(vector<pair<int,int> >&);
  bool remove(const int&, const int&);
  bool closePath();
  vector<vector<pair<int, int> > >& getPaths();
  vector<pair<int, int> >& getCurrentPath();
  bool victory();
};

#endif
