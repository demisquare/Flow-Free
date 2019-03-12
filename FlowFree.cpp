/*creare un display*/
#include "Level.h"

int main()
{
  if(!al_init())
  {
   cerr << "failed to initialize allegro!\n";
   return -1;
  }

  ALLEGRO_DISPLAY* display;

  float windowWidth = 640, windowHeight = 480;
  al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
  display = al_create_display(windowWidth, windowHeight);
  
  if(!display)
  {
   cerr << "failed to initialize allegro!\n";
   return -1;
  }
  else
  {
    windowWidth = al_get_display_width(display);
    windowHeight = al_get_display_height(display);

    int screenWidth = 640, screenHeight = 480;

    float sx = windowWidth/(float)screenWidth;
    float sy = windowHeight/(float)screenHeight;

    ALLEGRO_TRANSFORM trans;
    al_identity_transform(&trans);
    al_scale_transform(&trans, sx, sy);
    al_use_transform(&trans);
  }

    Level myLevel;

    al_rest(2.0); //attendi 2 secondi
    al_destroy_display(display); //distruggi display

    return 0;
}
