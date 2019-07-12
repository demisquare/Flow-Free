#ifndef MUSIC_H
#define MUSIC_H

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>

using namespace std;

class Music
{
private:
    //songs
    ALLEGRO_SAMPLE *menu;
    ALLEGRO_SAMPLE *game;

    //sfx
    ALLEGRO_SAMPLE *select;

    ALLEGRO_SAMPLE *win;
    ALLEGRO_SAMPLE *lose;

    ALLEGRO_SAMPLE_INSTANCE* menuInstance;
    ALLEGRO_SAMPLE_INSTANCE* gameInstance;
    
    bool isMenuPlaying = false;
    bool isGamePlaying = false;

public:
    Music();
    void init();

    void playMenu();
    void stopMenu();

    void playGame();
    void stopGame();

    void playSelect();

    void playRes(bool);

    ~Music();
};

#endif