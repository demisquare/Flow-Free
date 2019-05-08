#include "../head/Empty.h"

Empty::Empty(const unsigned x, const unsigned y):
  GameObj(x, y, BLACK){}

type Empty::getType()const{return EMPTY;}

void Empty::draw(){}