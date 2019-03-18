#include "../head/GraphicManager.h"

GraphicManager::GraphicManager() {}

GraphicManager::GraphicManager(const int &scale_w, const int &scale_h, const int &scale_x, const int &scale_y, ALLEGRO_BITMAP *buffer, ALLEGRO_DISPLAY *display)
{
    this->scale_h = scale_h;
    this->scale_w = scale_w;
    this->scale_x = scale_x;
    this->scale_y = scale_y;
    this->buffer = buffer;
    this->display = display;
}

GraphicManager::~GraphicManager()
{

}

int GraphicManager::drawMenu()
{
    if (!buffer)
        return 2;

    al_set_target_bitmap(buffer);
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();

    if (!queue)
        return 2;

    ALLEGRO_BITMAP *menu = al_load_bitmap("../images/background.png");

    if(!menu)
    {
        cout<<"Failed to load the menu bitmap";
        exit(-1);
    }

    //disegna menu...
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(menu, 0, 0, 0);

    al_set_target_bitmap(al_get_backbuffer(display));

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_scaled_bitmap(buffer, 0, 0, WINDOW_W, WINDOW_H, scale_x, scale_y, scale_w, scale_h, 0);

    al_flip_display();

    al_set_target_bitmap(buffer);

    //registra eventi...
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());

    while (true)
    {
        menu = al_load_bitmap("../images/background.png");
        if (!menu)
            return 2;
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu, 0, 0, 0);
        ALLEGRO_EVENT ev;
        al_wait_for_event(queue, &ev);
        switch (ev.type)
        {
            case ALLEGRO_EVENT_MOUSE_AXES: //movimento mouse
        
        	//sono su "Play!"
                 if (ev.mouse.x / (scale_w / WINDOW_W) >= 275 &&
                     ev.mouse.x / (scale_w / WINDOW_W) <= 370 &&
                     ev.mouse.y / (scale_h / WINDOW_H) >= 283 &&
                     ev.mouse.y / (scale_h / WINDOW_H) <= 315)

	           al_draw_filled_circle(252, 300, 7, PINK);
            
            
            //sono su "Options"
            else if (ev.mouse.x / (scale_w / WINDOW_W) >= 260 &&
                     ev.mouse.x / (scale_w / WINDOW_W) <= 379 &&
                     ev.mouse.y / (scale_h / WINDOW_H) >= 330 &&
                     ev.mouse.y / (scale_h / WINDOW_H) <= 363)

               al_draw_filled_circle(252, 350, 7, GREEN);
            
            
            //sono su "Quit"
            else if (ev.mouse.x / (scale_w / WINDOW_W) >= 283  &&
                     ev.mouse.x / (scale_w / WINDOW_W) <= 356  &&
                     ev.mouse.y / (scale_h / WINDOW_H) >= 421 &&
                     ev.mouse.y / (scale_h / WINDOW_H) <= 460 )
        
				al_draw_filled_circle(267, 444, 7, RED);
            
            
            else
                al_set_target_bitmap(buffer);
            
                break;
            
            case ALLEGRO_EVENT_KEY_DOWN:
                if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                    exit(1);
                break;
            
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                     if (ev.mouse.x / (scale_w / WINDOW_W) >= 275 &&
                         ev.mouse.x / (scale_w / WINDOW_W) <= 370 &&
                         ev.mouse.y / (scale_h / WINDOW_H) >= 283 &&
                         ev.mouse.y / (scale_h / WINDOW_H) <= 315)

                    return 1; //first level

                else if (ev.mouse.x / (scale_w / WINDOW_W) >= 260 &&
                         ev.mouse.x / (scale_w / WINDOW_W) <= 379 &&
                         ev.mouse.y / (scale_h / WINDOW_H) >= 165 &&
                         ev.mouse.y / (scale_h / WINDOW_H) <= 363)

                    return 3; //options

                else if (ev.mouse.x / (scale_w / WINDOW_W) >= 283 &&
                         ev.mouse.x / (scale_w / WINDOW_W) <= 356 &&
                         ev.mouse.y / (scale_h / WINDOW_H) >= 421 &&
                         ev.mouse.y / (scale_h / WINDOW_H) <= 460)

                    return 2; //quit
                break;
            
            /*case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                sound.playClick();
                break;*/

            default:
                break;
        }

        al_set_target_bitmap(al_get_backbuffer(display));
        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_draw_scaled_bitmap(buffer, 0, 0, WINDOW_W, WINDOW_H, scale_x, scale_y, scale_w, scale_h, 0);

        al_flip_display();
        
        al_set_target_bitmap(buffer);

        al_clear_to_color(al_map_rgb(0, 0, 0));
     
     
        if (menu != 0)
            al_destroy_bitmap(menu);
     
        menu = 0;
        
        al_flush_event_queue(queue);
    }
    al_destroy_event_queue(queue);
    return 1;
}


int GraphicManager::drawOptions()
{
    if(!buffer)
    {
        cout<<"Fatal error";
        exit(-1);
    }
    al_set_target_bitmap(buffer);
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    if(!queue){
        cout<<"Failed to create the event queue";
        exit(-1);
    }
    ALLEGRO_BITMAP *options = al_load_bitmap("../images/GameMode.png");
    if(!options){
        cout<<"Failed to load the options bitmap";
        exit(-1);
    }

    int mode = 4; //se è 4 torna al menu

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(options, 0, 0, 0);
    
    al_set_target_bitmap(al_get_backbuffer(display));

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_scaled_bitmap(buffer, 0, 0, WINDOW_W, WINDOW_H, scale_x, scale_y, scale_w, scale_h, 0);

    al_flip_display();

    al_set_target_bitmap(buffer);

    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());

    while (true)
    {
        options = al_load_bitmap("../images/GameMode.png");
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(options, 0, 0, 0);
        ALLEGRO_EVENT ev;
        al_wait_for_event(queue, &ev);

        switch (ev.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES: //movimento mouse
        
        //se sono su "Classic"
            if (ev.mouse.x / (scale_w / WINDOW_W) >= 243 &&
                ev.mouse.x / (scale_w / WINDOW_W) <= 395 &&
                ev.mouse.y / (scale_h / WINDOW_H) >= 132 &&
                ev.mouse.y / (scale_h / WINDOW_H) <= 188)
            
			    al_draw_filled_circle(227, 164, 8, ORANGE);
            
            
         //se sono su "Moves"
            else if (ev.mouse.x / (scale_w / WINDOW_W) >= 243 &&
                     ev.mouse.x / (scale_w / WINDOW_W) <= 395 &&
                     ev.mouse.y / (scale_h / WINDOW_H) >= 212 &&
                     ev.mouse.y / (scale_h / WINDOW_H) <= 268)
                 			
			    al_draw_filled_circle(227, 244, 8, YELLOW);
            
            
          //se sono su "Timer"
            else if (ev.mouse.x / (scale_w / WINDOW_W) >= 259 &&
                     ev.mouse.x / (scale_w / WINDOW_W) <= 376 &&
                     ev.mouse.y / (scale_h / WINDOW_H) >= 292 &&
                     ev.mouse.y / (scale_h / WINDOW_H) <= 348)
                  	
				al_draw_filled_circle(243, 316, 8, AQUA);
            
            else
                al_set_target_bitmap(buffer);
            
            break;
            
        case ALLEGRO_EVENT_KEY_DOWN:
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                return mode;
            break;
            
        /*case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            if (ev.mouse.x / (scale_w / 560) >= 205 && ev.mouse.x / (scale_w / 560) <= 403 && ev.mouse.y / (scale_h / 320) >= 77 && ev.mouse.y / (scale_h / 320) <= 117)
                mode = drawAssets(sound); //assets
            else if (ev.mouse.x / (scale_w / 560) >= 175 && ev.mouse.x / (scale_w / 560) <= 440 && ev.mouse.y / (scale_h / 320) >= 145 && ev.mouse.y / (scale_h / 320) <= 185)
                mode = drawDifficulty(sound); //difficolta
            else if (ev.mouse.x / (scale_w / 560) >= 250 && ev.mouse.x / (scale_w / 560) <= 390 && ev.mouse.y / (scale_h / 320) >= 210 && ev.mouse.y / (scale_h / 320) <= 260)
                return mode; //la modalità rimane classica
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            sound.playClick();
            break;*/

        default:
            break;
        }
        al_set_target_bitmap(al_get_backbuffer(display));
        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_draw_scaled_bitmap(buffer, 0, 0, WINDOW_W, WINDOW_H, scale_x, scale_y, scale_w, scale_h, 0);

        al_flip_display();

        al_set_target_bitmap(buffer);
        al_clear_to_color(al_map_rgb(0, 0, 0));
   
        if (options != 0)
            al_destroy_bitmap(options);
     
        options = 0;

        al_flush_event_queue(queue);
    }
    al_destroy_event_queue(queue);

    return mode;
}

