#include "../head/GameMap.h"

void GameMap::readLevel(const char* lvl)
  {
    ifstream OpenFile(lvl);
    while(!OpenFile.eof())
      for(unsigned i = 0; i < n; i++)
        for(unsigned j = 0; j < n; j++)
          OpenFile >> levelmap[i][j];  
    OpenFile.close();
  }

  GameMap::GameMap():map(new GameObj**[n]), levelmap(new char*[n])
  {
    for(unsigned i = 0; i < n; i++)
      {
        map[i] = new GameObj*[n];
        levelmap[i] = new char;
      }
  }

  void GameMap::load(const char* lvl)
  {
    //apri un file di testo e leggi il contenuto...
    readLevel(lvl);
    //disegna le palline logicamente...
    ALLEGRO_COLOR c;
    for(unsigned i = 0; i < n; i++)
      for(unsigned j = 0; j < n; j++)
      {
        switch (levelmap[i][j])
          {
            case 'r':
               c = RED;
               break;

            case 'g':
               c = GREEN;
               break;

            case 'b':
               c = BLUE;
               break;

            case 'y':
               c = YELLOW;
               break;

            default:
               map[i][j] = nullptr;
               break; 
          }
        if(map[i][j]!=nullptr)
           map[i][j] = new Ball(pos+j*(offset), pos+i*(offset), r, c);
      }   
  }
  void GameMap::draw(const unsigned &x, const unsigned &y)
  {
    for(unsigned i = 0; i < n; i++)
      for(unsigned j = 0; j < n; j++)
        {
          //disegna la griglia...
          al_draw_rectangle(x, y, x+offset*(i+1), y+offset*(j+1), WHITE, 4);
          //disegna le palline...
          if(map[i][j]!=nullptr)
             map[i][j]->draw();
        }
  }

 GameMap::~GameMap()
  {
    //distruggi tutti i puntatori...
    for(unsigned i = 0; i < n; i++)
    {
      for(unsigned j = 0; j < n; j++)
        if(map[i][j]!=nullptr)
          delete map[i][j];
      
      delete[] map[i];
    }
    delete[] map;

    for(unsigned i = 0; i < n; i++)
      delete levelmap[i];
    delete[] levelmap;
  }

  unsigned GameMap::size()const{return n;}
