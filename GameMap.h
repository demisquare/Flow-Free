#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GameObj.h"
#include <fstream>
#include <list>

//crea una matrice di oggetti (palline o percorsi)
class GameMap
{
private:
  ALLEGRO_BITMAP* grid;
  const unsigned n = 5;
  GameObj*** map;
  char** levelmap;
  unsigned x, y;

  void readLevel(const char* lvl)
  {
    ifstream OpenFile(lvl);

    while(!OpenFile.eof())
      for(unsigned i = 0; i < n; i++)
        for(unsigned j = 0; j < n; j++)
          OpenFile >> levelmap[i][j];
  
    OpenFile.close();
  }

public:
  GameMap():grid(NULL), map(new GameObj**[n]), levelmap(new char*[n])
  {

    //dichiara la matrice...
    for(unsigned i = 0; i < n; i++)
      map[i] = new GameObj*;

    for(unsigned i = 0; i < n; i++)
      levelmap[i] = new char;

  }

  void draw(const unsigned &x, const unsigned &y, const char* lvl)
  {
    //disegna la mappa...
    grid = al_load_bitmap("Images/grid5x5.png"); //grid...
    al_draw_scaled_bitmap(grid,
                          0, 0,                               // source origin
                          al_get_bitmap_width(grid),          // source width
                          al_get_bitmap_height(grid),         // source height
                          x, y,                               // target origin
                          al_get_bitmap_width(grid)*0.5,      // source width
                          al_get_bitmap_height(grid)*0.5,     // target dimensions
                          0                                   // flags
                        );

    //apri un file di testo e leggi il contenuto...
    readLevel(lvl);

    //disegna le palline...
    for(unsigned i = 0; i < n; i++)
      for(unsigned j = 0; j < n; j++)
      {
        switch (levelmap[i][j])
        {
          case 'r':
             map[i][j] = new Ball(85+i*(x+20), 85+j*(y+20), 30, RED);
             map[i][j]->draw();
             break;

          case 'g':
             map[i][j] = new Ball(85+i*(x+20), 85+j*(y+20), 30, GREEN);
             map[i][j]->draw();
             break;

          case 'b':
             map[i][j] = new Ball(85+i*(x+20), 85+j*(y+20), 30, BLUE);
             map[i][j]->draw();
             break;
        }
      }
  }

  virtual ~GameMap()
  {
    //distruggi tutte le bitmap...
    al_destroy_bitmap(grid);
    
    //distruggi tutti i puntatori...
    for(unsigned i = 0; i < n; i++)
        {
          for(unsigned j = 0; j < n; j++)
            delete[] map[i][j];
          delete[] map[i];
        }
    delete map;

    for(unsigned i = 0; i < n; i++)
        delete[] levelmap[i];
        
    delete levelmap;
  }

  unsigned size()const{return n;}

  GameObj* getObj(const unsigned &x, const unsigned &y) const{return map[x][y];}

  unsigned getColors()const
  {
    //restituisce il numero distinto di colori presenti sulla mappa...
    /*list<ALLEGRO_COLOR> colors;

    for(unsigned i = 0; i < n; i++)
      for(unsigned j = 0; j < n; j++)
        {
          bool ok = true;
          for(auto c: colors)
            if(map[i][j]->getColor() == c) //manca operator== per ALLEGRO_COLOR
              ok = false;
          colors.push_back(map[i][j]->getColor());
        }

    return colors.size();*/
  }

};

#endif
