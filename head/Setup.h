#ifndef SETUP_H
#define SETUP_H

#include "Level.h"

class Setup:public GameEngine
{
private:
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