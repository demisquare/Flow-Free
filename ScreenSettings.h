#ifndef SCREENSETTINGS_H
#define SCREENSETTINGS_H

#define WIDTH 640
#define HEIGHT 480

#include <allegro5/allegro.h>
#include <iostream>

using namespace std;

class ScreenSettings
{
private:
    ALLEGRO_DISPLAY* display;
public:
    ScreenSettings()
    {
        float windowWidth = WIDTH, windowHeight = HEIGHT;
        al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
        display = al_create_display(windowWidth, windowHeight);
  
         if(!display)
            cerr << "failed to initialize allegro!\n";
  
        else
        {
            //operazione di resize...
            windowWidth = al_get_display_width(display);
            windowHeight = al_get_display_height(display);

            int screenWidth = WIDTH, screenHeight = HEIGHT;

            float sx = windowWidth/(float)screenWidth;
            float sy = windowHeight/(float)screenHeight;

            ALLEGRO_TRANSFORM trans;
            al_identity_transform(&trans);
            al_scale_transform(&trans, sx, sy);
            al_use_transform(&trans);
        }
    }

    ~ScreenSettings()
    {
        al_destroy_display(display);
    }
};

#endif