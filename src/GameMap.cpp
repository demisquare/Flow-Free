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
  
  void GameMap::draw(const unsigned &x, const unsigned &y, const char* lvl)
  {
    //apri un file di testo e leggi il contenuto...
    readLevel(lvl);

    unsigned pos = 90;
    unsigned offset = 140;
    unsigned r = 65;

    //disegna le palline...
    for(unsigned i = 0; i < n; i++)
      for(unsigned j = 0; j < n; j++)
        {
          //disegna la griglia...
          al_draw_rectangle(x, y, x+offset*(i+1), y+offset*(j+1), WHITE, 4);
          switch (levelmap[i][j])
          {
            case 'r':
               map[i][j] = new Ball(pos+j*(offset), pos+i*(offset), r, RED);
               map[i][j]->draw();
               break;

            case 'g':
               map[i][j] = new Ball(pos+j*(offset), pos+i*(offset), r, GREEN);
               map[i][j]->draw();
               break;

            case 'b':
               map[i][j] = new Ball(pos+j*(offset), pos+i*(offset), r, BLUE);
               map[i][j]->draw();
               break;

            case 'y':
               map[i][j] = new Ball(pos+j*(offset), pos+i*(offset), r, YELLOW);
               map[i][j]->draw();
               break;

            default:
               map[i][j] = nullptr;
               break; 
          }
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
