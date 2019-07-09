#include "../head/Music.h"

 Music::Music():song(NULL), hover(NULL), select(NULL), win(NULL), lose(NULL)
{
        if(!al_install_audio())
        {
            cerr << "failed to initialize audio!\n";
            exit(-1);
        }

        if(!al_init_acodec_addon())
        {
            cerr << "failed to initialize audio codecs!\n";
            exit(-1);
        }

        if (!al_reserve_samples(10))
        {
            cerr << "failed to reserve samples!\n";
            exit(-1);
        }

        song = al_load_sample("../music/menu.wav");
        if(!song)
        {
            cerr << "failed to load song!\n";
            exit(-1);
        }
        hover = al_load_sample("../music/select.wav");
        if(!hover)
        {
            cerr << "failed to load hover sfx!\n";
            al_destroy_sample(song);
            exit(-1);
        }
        select = al_load_sample("../music/select.wav");
        if(!select)
        {
            cerr << "failed to load select sfx!\n";
            al_destroy_sample(song);
            al_destroy_sample(hover);
            exit(-1);
        }
        win = al_load_sample("../music/win.wav");
        if(!win)
        {
            cerr << "failed to load win sfx!\n";
            al_destroy_sample(song);
            al_destroy_sample(hover);
            al_destroy_sample(select);
            exit(-1);
        }
        lose = al_load_sample("../music/lose.wav");
        if(!select)
        {
            cerr << "failed to load lose sfx!\n";
            al_destroy_sample(song);
            al_destroy_sample(hover);
            al_destroy_sample(select);
            al_destroy_sample(win);
            exit(-1);
        }
        songInstance = al_create_sample_instance(song);
        if(!songInstance)
        {
            cerr << "failed to create sample instance!\n";
            al_destroy_sample(song);
            al_destroy_sample(select);
            al_destroy_sample(hover);
            al_destroy_sample(win);
            al_destroy_sample(lose);
            exit(-1);
        }

        al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
        al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());

}
void Music::playSong()
{
    al_play_sample_instance(songInstance);
}
void Music::stopSong()
{
    al_stop_sample_instance(songInstance);
}
void Music::playSelect()
{
    al_play_sample(select, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
}
void Music::playHover()
{
    al_play_sample(hover, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
}
void Music::playWin()
{
    stopSong();
    al_play_sample(win, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
}
void Music::playLose()
{
    stopSong();
    al_play_sample(lose, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
}
 Music::~Music()
{
    al_destroy_sample(song);
    al_destroy_sample(select);
    al_destroy_sample(hover);
    al_destroy_sample(win);
    al_destroy_sample(lose);
    al_destroy_sample_instance(songInstance);
    al_uninstall_audio();
}