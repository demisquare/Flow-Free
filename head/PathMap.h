#ifndef PATHMAP_H
#define PATHMAP_H

#include <utility>
#include <iostream>
#include "GameMap.h"

//crea una matrice di percorsi
class PathMap
{
private:
  vector<vector<pair<int, int> > > map;
  vector<pair<int, int> > currentPath;
  vector<ALLEGRO_COLOR> colors;
  GameMap gm;

  bool isClosed(vector<pair<int,int> > );
  bool isSigned(pair<int, int>);
  bool isUnique();

public:  
  GameMap& getLogic();
  void load(const int&);
  void add(const int&, const int&, ALLEGRO_COLOR);
  vector<vector<pair<int, int> > >& getPaths();
  vector<pair<int, int> >& getCurrentPath();
  pair<int, int> getLastCoords();
  bool victory();
};

#endif
