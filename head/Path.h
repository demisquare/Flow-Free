#ifndef PATH_H
#define PATH_H

#include "GameObj.h"

// percorsi...
class Path:public GameObj
{
public:
  Path(const unsigned x, const unsigned y, const ALLEGRO_COLOR c);
  type getType()const;
  void draw();
};

#endif