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
    ALLEGRO_SAMPLE *song;

    //sfx
    ALLEGRO_SAMPLE *hover;
    ALLEGRO_SAMPLE *select;

    ALLEGRO_SAMPLE *win;
    ALLEGRO_SAMPLE *lose;

    ALLEGRO_SAMPLE_INSTANCE* songInstance;
    
public:
    Music();

    bool isRunning = true;

    void playSong();
    void stopSong();

    void playSelect();
    void playHover();

    void playRes(bool);

    ~Music();
};

#endif