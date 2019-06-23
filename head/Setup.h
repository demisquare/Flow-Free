#ifndef SETUP_H
#define SETUP_H

#include "Level.h"

class Setup:public GameEngine
{
private:
    float windowWidth = WIDTH, windowHeight = HEIGHT;
    float sx, sy;

    int scale;

    int scaleW, scaleH;
    int scaleX, scaleY;

    void init_display();

    void drawMenu();
    void drawOptions();

    vector<Level> levels;
    int nLevels = 3;
    void runLevel(int);


public:
    Setup();
    
    void menu();
    void options();

    ~Setup();
};

#endif