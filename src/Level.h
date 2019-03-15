#ifndef LEVEL_H
#define LEVEL_H

#include "GameMap.h"

class Level
{
private:
  GameMap myMap;
  ALLEGRO_BITMAP* grid;

  const unsigned x = 20, y = 20;

public:
  Level():grid(NULL){}

  void run(const char* lvl)
  {
    al_clear_to_color(BLACK);

        //disegna la mappa...
        /*grid = al_load_bitmap("images/GridLevel.png"); //grid...
        al_draw_scaled_bitmap(grid,
                              0, 0,                               // source origin
                              al_get_bitmap_width(grid),          // source width
                              al_get_bitmap_height(grid),         // source height
                              x, y,                               // target origin
                              al_get_bitmap_width(grid)*1.5,      // source width
                              al_get_bitmap_height(grid)*1.5,     // target dimensions
                              0);                                 // flags*/
                              
        myMap.draw(x, y, lvl);
        al_flip_display();//aggiorna display
  }

  ~Level()
  {
    al_destroy_bitmap(grid); //distruggi bitmap
  }

};
#endif
