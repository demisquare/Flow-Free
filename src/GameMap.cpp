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
    for(unsigned i = 0; i < n; i++)
    {
      for(unsigned j = 0; j < n; j++)
      {
        switch (levelmap[i][j])
        {
          case 'r':
             map[i][j] = new Ball(pos+j*(offset), pos+i*(offset), r, RED);
             break;
          case 'g':
             map[i][j] = new Ball(pos+j*(offset), pos+i*(offset), r, GREEN);
             break;
          case 'b':
             map[i][j] = new Ball(pos+j*(offset), pos+i*(offset), r, BLUE);
             break;
          case 'y':
             map[i][j] = new Ball(pos+j*(offset), pos+i*(offset), r, YELLOW);
             break;
          default:
             map[i][j] = nullptr;
             break; 
        }
        /*if(map[i][j] != nullptr)
           map[i][j] = new Ball(pos+j*(offset), pos+i*(offset), r, c);*/
      }  
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
             map[i][j]->draw();   //chiama il metodo draw() di Ball.cpp
        }
}

GameMap::~GameMap()
{
    //distruggi palline e percorsi...
    for(unsigned i = 0; i < n; i++)
    {
      for(unsigned j = 0; j < n; j++)
        if(map[i][j]!=nullptr)
          delete map[i][j];
      
      delete[] map[i];
    }
    delete[] map;

    //distruggi la mappa dei colori...
    for(unsigned i = 0; i < n; i++)
      delete levelmap[i];
    delete[] levelmap;
}

//ottieni coordinate della mappa con il mouse...
int GameMap::get(const int &mouse)const{return (int(mouse-x)/offset);}

//restituisce l'oggetto in corrispondenza del mouse...
GameObj* GameMap::getObj(const int &mouseX, const int &mouseY)const
{return map[get(mouseY)][get(mouseX)];}

//verifica se siamo sulla mappa o no...
bool GameMap::inMap(const int &mouseX, const int &mouseY)const
{return get(mouseX) < n && get(mouseY) < n;}

unsigned GameMap::size()const{return n;}
