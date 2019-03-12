#ifndef LEVEL_H
#define LEVEL_H

#include <allegro5/allegro_image.h>
#include "GameMap.h"

class Level
{
private:
  GameMap myMap;
  ALLEGRO_BITMAP* grid;

  const unsigned x = 50, y = 50;

public:
  Level():grid(NULL)
  {
    if(!al_init_image_addon())
      cerr << "failed to initialize menu!\n";

    else
      {
        al_clear_to_color(BLACK);

        //disegna la mappa...
        grid = al_load_bitmap("Images/grid5x5.png"); //grid...
        al_draw_scaled_bitmap(grid,
                          0, 0,                               // source origin
                          al_get_bitmap_width(grid),          // source width
                          al_get_bitmap_height(grid),         // source height
                          x, y,                             // target origin
                          al_get_bitmap_width(grid)*0.5,      // source width
                          al_get_bitmap_height(grid)*0.5,     // target dimensions
                          0);                                 // flags


        myMap.draw(x, y, "level1.txt");

        al_flip_display(); //aggiorna display
      }

  }

  ~Level()
  {
    al_destroy_bitmap(grid); //distruggi bitmap
    //myMap.~GameMap(); //distruggi mappa
  }

};
#endif
