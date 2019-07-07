#include "../head/GameMap.h"
void GameMap::readLevel(const int& lvl)
{
  ifstream OpenFile("../levels/level" + to_string(lvl) + ".txt");
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
void GameMap::load(const int& lvl)
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
           map[i][j] = new Ball(gap+(offset/2)+(j*offset), gap+(offset/2)+(i*offset), r, RED);
           break;
        case 'g':
           map[i][j] = new Ball(gap+(offset/2)+(j*offset), gap+(offset/2)+(i*offset), r, GREEN);
           break;
        case 'b':
           map[i][j] = new Ball(gap+(offset/2)+(j*offset), gap+(offset/2)+(i*offset), r, BLUE);
           break;
        case 'y':
           map[i][j] = new Ball(gap+(offset/2)+(j*offset), gap+(offset/2)+(i*offset), r, YELLOW);
           break;
        case 'o':
           map[i][j] = new Ball(gap+(offset/2)+(j*offset), gap+(offset/2)+(i*offset), r, ORANGE);
           break;
        default:
           map[i][j] = new Empty(gap+(offset/2)+(j*offset), gap+(offset/2)+(i*offset));
           break; 
      }
    }  
  }   
}

GameMap::~GameMap()
{
  //distruggi palline e percorsi...
  for(unsigned i = 0; i < n; i++)
    for(unsigned j = 0; j < n; j++)
      delete map[i][j];
}

//aggiunge un percorso alla mappa in posizione (i, j)
void GameMap::addPath(const int &i, const int &j, ALLEGRO_COLOR color)
{
  if(map[i][j]->getType() == EMPTY)
  {
    delete map[i][j];
    map[i][j] = new Path(gap+(offset/2)+(j*offset), gap+(offset/2)+(i*offset), color);
    //cout << "added: " << map[i][j]->getLogicY() << " - " << map[i][j]->getLogicX() << endl;
  }
}

//rimuove un percorso con coordinate (i, j)
void GameMap::removePath(const int &i, const int &j)
{
  if(map[i][j]->getType()==PATH)
  {
    delete map[i][j];
    map[i][j] = new Empty(gap+(offset/2)+(j*offset), gap+(offset/2)+(i*offset));
  }
}

void GameMap::clearPath()
{
  for(unsigned i = 0; i < n; i++)
    for(unsigned j = 0; j < n; j++)
      removePath(i, j);
}

//ottieni coordinate della mappa con il mouse...
int GameMap::get(const int &mouse)const{return (int(mouse-gap)/offset);}

//restituisce l'oggetto in corrispondenza del mouse...
GameObj* GameMap::getObj(const int &mouseX, const int &mouseY)const
{return map[get(mouseY)][get(mouseX)];}

//restituisce l'oggetto attraverso le coordinate logiche...
GameObj* GameMap::getLogicObj(const int &i, const int &j)const
{return map[i][j];}

//verifica se siamo sulla mappa o no...
bool GameMap::inMap(const int &mouseX, const int &mouseY)const
{return get(mouseX) < n && get(mouseY) < n;}

//restituisce il numero distinto di colori presenti...
unsigned GameMap::getColors()const
{
  vector<ALLEGRO_COLOR> colors;
  for(unsigned i = 0; i < n; i++)
    for(unsigned j = 0; j < n; j++)
      if(find(colors.begin(), colors.end(), map[i][j]->getColor()) == colors.end()
      && map[i][j]->getType() == BALL)
        colors.push_back(map[i][j]->getColor());
    

  return colors.size();
            
    
}

//verifica se la mappa è piena...
bool GameMap::isFull()const
{
  for(unsigned i = 0; i < n; i++)
    for(unsigned j = 0; j < n; j++)
      if(map[i][j]->getType() == EMPTY)
        return false;
  return true;
}

unsigned GameMap::size()const{return n;}
