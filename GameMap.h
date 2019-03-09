#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GameObj.h"

//crea una matrice di oggetti (palline o percorsi)
class GameMap
{
private:
  ALLEGRO_BITMAP* grid;
  const unsigned n = 5;
  GameObj*** map;
  unsigned x, y;

public:
  GameMap():grid(NULL), map(new GameObj**[n])
  {

    //dichiara la matrice...
    for(unsigned i = 0; i < n; i++)
      map[i] = new GameObj*;



    //apri un file di testo e leggi il contenuto.
    //verifica se non esistono più di due palline di un certo colore.
    //se sì, carica i valori nella mappa e disegna le palline.

  }

  void draw(const unsigned &x, const unsigned &y)
  {
    //disegna la mappa...
    grid = al_load_bitmap("grid5x5.png"); //grid...
    al_draw_scaled_bitmap(grid,
                          0, 0,                               // source origin
                          al_get_bitmap_width(grid),          // source width
                          al_get_bitmap_height(grid),         // source height
                          x, y,                               // target origin
                          al_get_bitmap_width(grid)*0.5,      // source width
                          al_get_bitmap_height(grid)*0.5,     // target dimensions
                          0                                   // flags
                        );

    //disegna le palline...
    for(unsigned i = 0; i < n; i++)
      for(unsigned j = 0; j < n; j++)
      {
        map[i][j] = new Ball(85+i*(x+20), 85+j*(y+20), 30, RED); //rivedere il costruttore...
        map[i][j]->draw();
      }
  }

  virtual ~GameMap()
  {
    al_destroy_bitmap(grid);
    //distruggi tutti i puntatori...

    for(unsigned i = 0; i < n; i++)
        {
          for(unsigned j = 0; j < n; j++)
            delete[] map[i][j];
          delete[] map[i];
        }
    delete map;
  }

  unsigned size()const{return n;}

  GameObj* getObj(const unsigned &x, const unsigned &y) const{return map[x][y];}

   /*bool isFull()const
  {
    //scorri per tutta la matrice, se trova un valore vuoto restituisci false.
    if(!empty())
    {
      for(int i = 0; i < size(); i++)
        for(int j = 0; j < size(); j++)
          //se trova un valore...
          if(getObj(i, j) == nullptr) //rivedere...
          return false;
    }
    return true;
  }*/

  unsigned getColors()const
  {
    //restituisce il numero distinto di colori...
  }

};

#endif
