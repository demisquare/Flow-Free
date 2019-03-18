#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GameObj.h"
#include <fstream>
#include <iostream>


//crea una matrice di oggetti (palline o percorsi)
class GameMap
{
private:
  const unsigned n = 5;
  GameObj*** map;
  char** levelmap;
  unsigned x, y;

  void readLevel(const char* lvl)
  {
    ifstream OpenFile(lvl);

    while(!OpenFile.eof())
      for(unsigned i = 0; i < n; i++)
        for(unsigned j = 0; j < n; j++)
          OpenFile >> levelmap[i][j];
  
    OpenFile.close();
  }

public:
  GameMap();
  void draw(const unsigned &x, const unsigned &y, const char* lvl);
 ~GameMap();
  unsigned size()const;
};

#endif
