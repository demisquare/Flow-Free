#ifndef EMPTY_H
#define EMPTY_H

#include "GameObj.h"

//segnaposto vuoto...
class Empty:public GameObj
{
public:
  Empty(const unsigned x, const unsigned y);

  type getType()const;
  void draw();

};

#endif