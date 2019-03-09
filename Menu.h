#ifndef MENU_H
#define MENU_H

#include <allegro5/allegro_image.h>
#include "GameMap.h"

class Menu
{
private:
  ALLEGRO_BITMAP* title;

public:
  Menu():title(NULL)
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

        GameMap myMap(5);
        myMap.draw();

        al_flip_display(); //aggiorna display
      }

  }

  ~Menu()
  {
    al_destroy_bitmap(title); //distruggi prima le bitmap
  }

};
#endif
