#ifndef MUSIC_H
#define MUSIC_H

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>

using namespace std;

// gestore musica...
class Music
{
private:
    //background...
    ALLEGRO_SAMPLE *menu;
    ALLEGRO_SAMPLE *game;

    //sfx selezione...
    ALLEGRO_SAMPLE *select;

    //sfx risultati...
    ALLEGRO_SAMPLE *win;
    ALLEGRO_SAMPLE *lose;

    // istanze per gestire i background...
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