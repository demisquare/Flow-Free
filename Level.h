#ifndef LEVEL_H
#define LEVEL_H

#include <allegro5/allegro_image.h>
#include "GameMap.h"

class Level
{
private:
  ALLEGRO_BITMAP* title;

  GameMap myMap;

public:
  Level():title(NULL)
  {
    if(!al_init_image_addon())
      cerr << "failed to initialize menu!\n";

    else
      {
        al_clear_to_color(BLACK);
        /*title = al_load_bitmap("flow-free-menu.png"); //title...
        al_draw_scaled_bitmap(title,
                              0, 0,                                // source origin
                              al_get_bitmap_width(title),          // source width
                              al_get_bitmap_height(title),         // source height
                              50, 50,                              // target origin
                              al_get_bitmap_width(title)*0.3,      // source width
                              al_get_bitmap_height(title)*0.3,     // target dimensions
                              0                                    // flags
                            );*/

        myMap.draw(50, 50, "level1.txt");

        al_flip_display(); //aggiorna display
      }

  }

  ~Level()
  {
    al_destroy_bitmap(title); //distruggi prima le bitmap

    myMap.~GameMap(); //distruggi la mappa
  }

};
#endif
