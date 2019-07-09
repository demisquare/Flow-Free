#include "../head/Music.h"

Music::Music():menu(NULL), game(NULL), select(NULL), win(NULL), lose(NULL){}

void Music::init()
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

    menu = al_load_sample("../assets/music/menu.wav");
    if(!menu)
    {
        cerr << "failed to load menu song!\n";
        exit(-1);
    }
    game = al_load_sample("../assets/music/game.wav");
    if(!game)
    {
        al_destroy_sample(menu);
        cerr << "failed to load game song!\n";
        exit(-1);
    }
    select = al_load_sample("../assets/music/select.wav");
    if(!select)
    {
        cerr << "failed to load select sfx!\n";
        al_destroy_sample(menu);
        al_destroy_sample(game);
        exit(-1);
    }
    win = al_load_sample("../assets/music/win.wav");
    if(!win)
    {
        cerr << "failed to load win sfx!\n";
        al_destroy_sample(menu);
        al_destroy_sample(game);
        al_destroy_sample(select);
        exit(-1);
    }
    lose = al_load_sample("../assets/music/lose.wav");
    if(!select)
    {
        cerr << "failed to load lose sfx!\n";
        al_destroy_sample(menu);
        al_destroy_sample(game);
        al_destroy_sample(select);
        al_destroy_sample(win);
        exit(-1);
    }
    menuInstance = al_create_sample_instance(menu);
    if(!menuInstance)
    {
        cerr << "failed to create sample menu instance!\n";
        al_destroy_sample(menu);
        al_destroy_sample(game);
        al_destroy_sample(select);
        al_destroy_sample(win);
        al_destroy_sample(lose);
        exit(-1);
    }

    al_set_sample_instance_playmode(menuInstance, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_gain(menuInstance, 0.3);
    al_attach_sample_instance_to_mixer(menuInstance, al_get_default_mixer());

    gameInstance = al_create_sample_instance(game);
    if(!gameInstance)
    {
        cerr << "failed to create sample game instance!\n";
        al_destroy_sample(menu);
        al_destroy_sample(game);
        al_destroy_sample(select);
        al_destroy_sample(win);
        al_destroy_sample(lose);
        exit(-1);
    }

    al_set_sample_instance_playmode(gameInstance, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_gain(gameInstance, 0.15);
    al_attach_sample_instance_to_mixer(gameInstance, al_get_default_mixer());

}

void Music::playMenu()
{
    if(!isMenuPlaying)
    {
        al_play_sample_instance(menuInstance);
        isMenuPlaying = true;    
    }
}
void Music::stopMenu()
{
    if(isMenuPlaying)
    {
        al_stop_sample_instance(menuInstance);
        isMenuPlaying = false;    
    }
}

void Music::playGame()
{
    if(!isGamePlaying)
    {
        al_play_sample_instance(gameInstance);
        isGamePlaying = true;    
    }
}
void Music::stopGame()
{
    if(isGamePlaying)
    {
        al_stop_sample_instance(gameInstance);
        isGamePlaying = false;    
    }
}

void Music::playSelect()
{
    al_play_sample(select, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
}
void Music::playRes(bool res)
{
    stopGame();
    if(res)
        al_play_sample(win, 0.2, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
    else
        al_play_sample(lose, 0.2, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
}

 Music::~Music()
{
    al_destroy_sample(menu);
    al_destroy_sample(game);
    al_destroy_sample(select);
    al_destroy_sample(win);
    al_destroy_sample(lose);
    al_destroy_sample_instance(menuInstance);
    al_destroy_sample_instance(gameInstance);
    al_uninstall_audio();
}