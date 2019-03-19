#ifndef SETUP_H
#define SETUP_H

#define WIDTH 640
#define HEIGHT 480
#define FPS 30

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

#include "Color.h"

using namespace std;

class Setup
{
private:
    ALLEGRO_DISPLAY* display;
    ALLEGRO_BITMAP * buffer;

    float windowWidth = WIDTH, windowHeight = HEIGHT;
    float sx, sy;

    int scale;

    int scaleW, scaleH;
    int scaleX, scaleY;

    void init_display();

public:
    Setup();
    void drawMenu();
    ~Setup();
};

#endif