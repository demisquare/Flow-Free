#include "../head/Level.h"

  Level::Level(){}

  void Level:: run(const char* lvl)
  {
    al_clear_to_color(BLACK);
    myMap.draw(x, y, lvl);
    al_flip_display();
  }

  Level::~Level(){al_clear_to_color(BLACK);}
