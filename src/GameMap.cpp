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
GameMap::GameMap()
{
  levelmap.resize(n);
  for(int i = 0; i < n; i++)
    levelmap[i].resize(n);

  map.resize(n);
  for(int i = 0; i < n; i++)
    map[i].resize(n);
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
             map[i][j] = new Empty(pos+j*(offset), pos+i*(offset));
             break; 
        }
        /*if(map[i][j] != nullptr)
           map[i][j] = new Ball(pos+j*(offset), pos+i*(offset), r, c);*/
      }  
    }   
}

void GameMap::draw()
{
    for(unsigned i = 0; i < n; i++)
      for(unsigned j = 0; j < n; j++)
        {
          //disegna la griglia...
          al_draw_rectangle(gap, gap, gap+offset*(i+1), gap+offset*(j+1), WHITE, 4);

          //disegna le palline...
          if(map[i][j]->getType()!=EMPTY)
             map[i][j]->draw();   //chiama il metodo draw() di Ball.cpp
        }
}

GameMap::~GameMap()
{
  //distruggi palline e percorsi...
  for(unsigned i = 0; i < n; i++)
    for(unsigned j = 0; j < n; j++)
      delete map[i][j];
}

//aggiunge un oggetto alla mappa, sostituendo il precedente, in posizione (i, j)
void GameMap::add(GameObj* g, const int &i, const int &j)
{
  delete map[i][j];
  map[i][j] = g;
}

//rimuove l'oggetto con coordinate (i,j)
void GameMap::remove(const int &i, const int &j)
{
  delete map[i][j];
  map[i][j] = new Empty(pos+j*(offset), pos+i*(offset));
}

//ottieni coordinate della mappa con il mouse...
int GameMap::get(const int &mouse)const{return (int(mouse-gap)/offset);}

//restituisce l'oggetto in corrispondenza del mouse...
GameObj* GameMap::getObj(const int &mouseX, const int &mouseY)const
{return map[get(mouseY)][get(mouseX)];}

//verifica se siamo sulla mappa o no...
bool GameMap::inMap(const int &mouseX, const int &mouseY)const
{return get(mouseX) < n && get(mouseY) < n;}

unsigned GameMap::size()const{return n;}
