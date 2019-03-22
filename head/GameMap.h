#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GameObj.h"
#include <fstream>
<<<<<<< HEAD
#include <iostream>

=======
>>>>>>> master

//crea una matrice di oggetti (palline o percorsi)
class GameMap
{
private:
  const unsigned n = 5;
  GameObj*** map;
  char** levelmap;
  unsigned x, y;

<<<<<<< HEAD
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
=======
  void readLevel(const char*);

public:
  GameMap();
  
  void draw(const unsigned &, const unsigned &, const char*);

 ~GameMap();
  

  unsigned size()const;

  //GameObj* getObj(const unsigned &, const unsigned &);

  unsigned getColors()const;

  bool isFull()const;

>>>>>>> master
};

#endif
