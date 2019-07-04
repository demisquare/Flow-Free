#include "../head/GameEngine.h"

void GameEngine::resize(ALLEGRO_DISPLAY* display)
{
    windowHeight = al_get_display_height(display);
    windowWidth = al_get_display_width(display);

    sx = windowWidth / float(WIDTH);
    sy = windowHeight / float(HEIGHT);

    scale = std::min(sx, sy);

    scaleW = WIDTH * scale;
    scaleH = HEIGHT * scale;
    
    scaleX = (windowWidth - scaleW) / 2;
    scaleY = (windowHeight - scaleH) / 2;
}

void GameEngine::init_display()
{
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);


    display = al_create_display(WIDTH, HEIGHT);
    if(!display)
    {
        cerr << "Fatal error, unable to create a display\n";
        exit(-1);
    }
    
    buffer = al_create_bitmap(WIDTH, HEIGHT);
    if(!buffer)
    {
        cout << "Fatal error, unable to create a buffer\n";
        exit(-1);
    }

    if(!al_init_font_addon())
    {
      cerr << "failed to initialize font!\n";
      exit(-1);
    }

    if(!al_init_ttf_addon())
    {
     cerr << "failed to initialize ttf!\n";
     exit(-1);
    }

    font = al_load_font("../images/Aberus.ttf", 30, 0);
    if(!font)
    {
        cerr << "failed to load font!\n";
        exit(-1);
    }
    
    //operazione di resize...
    resize(display);         
    al_set_target_bitmap(buffer);
    al_clear_to_color(BLACK);
}

void GameEngine::cursor(int mouseX, int mouseY)
{
    al_draw_filled_circle(mouseX, mouseY, 7, WHITE);
}

void GameEngine::drawPath(vector<pair<int,int> > path, const GameMap& gm)
{
    if(path.size() >= 2)
    {
        ALLEGRO_COLOR color = gm.getLogicObj(path.front().first, path.front().second)->getColor();
        
        //scorri gli elementi del singolo percorso a coppie...
        for(int i = 0; i < path.size()-1; i++)
        {
            int x1 = gm.getLogicObj(path.at(i).first, path.at(i).second)->getX();
            int y1 = gm.getLogicObj(path.at(i).first, path.at(i).second)->getY();

            int x2 = gm.getLogicObj(path.at(i+1).first, path.at(i+1).second)->getX();
            int y2 = gm.getLogicObj(path.at(i+1).first, path.at(i+1).second)->getY();

            al_draw_line(x1, y1,
                         x2, y2,
                         color, r/4); 
        }
    }
}

void GameEngine::drawScore(Score& score, const unsigned& mode)
{
    al_draw_filled_rectangle(gap+(offset*5)+(offset/2),
                             gap,
                             gap+(offset*5)+(offset/2)*(offset*2),
                             gap+(offset*5), ORANGE);

    al_draw_textf(font, BLACK, gap+(offset*5)+(offset/2)*3.75, gap*2, ALLEGRO_ALIGN_CENTER, "Score:");
    al_draw_textf(font, BLACK, gap+(offset*5)+(offset/2)*3.75, gap*3, ALLEGRO_ALIGN_CENTER, "Moves: %i / %i", score.getMoves(), score.getRemainingMoves());

    if(mode == 2)
        al_draw_textf(font, BLACK, gap+(offset*5)+(offset/2)*3.75, gap*4, ALLEGRO_ALIGN_CENTER, "Time left: %i", score.getTimeLeft());
}

void GameEngine::drawMap(PathMap& pm)
{    
    for(unsigned i = 0; i < pm.getLogic().size(); i++)
        for(unsigned j = 0; j < pm.getLogic().size(); j++)
        {
            //disegna la griglia...
            al_draw_rectangle(gap, gap, gap+offset*(i+1), gap+offset*(j+1), WHITE, r/16);
            //disegna le palline e i percorsi...
            pm.getLogic().getLogicObj(i, j)->draw();   //chiama il metodo draw() di Ball e Path
        }
    
    drawPath(pm.getCurrentPath(), pm.getLogic());
    //scorri per tutti i percorsi...
    for(auto path: pm.getPaths())
        drawPath(path, pm.getLogic());    
}

void GameEngine::drawMenu(int mouseX, int mouseY)
{
    //sono su "Play!"
        if(mouseX >= 275 &&
           mouseX <= 370 &&
           mouseY >= 283 &&
           mouseY <= 315)

        al_draw_filled_circle(252, 300, 7, PINK);

    //sono su "Options"
    else if (mouseX >= 260 &&
             mouseX <= 379 &&
             mouseY >= 330 &&
             mouseY <= 363)

        al_draw_filled_circle(252, 350, 7, GREEN);

    //sono su "Quit"
    else if (mouseX >= 283 &&
             mouseX <= 356 &&
             mouseY >= 421 &&
             mouseX <= 460)

        al_draw_filled_circle(267, 444, 7, RED);
          
}

void GameEngine::drawOptions(int mouseX, int mouseY)
{
     //se sono su "Classic"
        if (mouseX >= 243 &&
            mouseX <= 395 &&
            mouseY >= 132 &&
            mouseY <= 188)
                      
		      al_draw_filled_circle(227, 164, 8, ORANGE);
        
        
     //se sono su "Moves"
        else if (mouseX >= 243 &&
                 mouseX <= 395 &&
                 mouseY >= 212 &&
                 mouseY <= 268)
               			
		        al_draw_filled_circle(227, 244, 8, YELLOW);
        
        
      //se sono su "Timer"
        else if (mouseX >= 259 &&
                 mouseX <= 376 &&
                 mouseY >= 292 &&
                 mouseY <= 348)
                    	
		 	      al_draw_filled_circle(243, 316, 8, AQUA);

        //sono su "Back"
        else if (mouseX >= 278 &&
                 mouseX <= 361 &&
                 mouseY >= 417 &&
                 mouseY <= 450)

            al_draw_filled_circle(267, 435, 7, RED);

}