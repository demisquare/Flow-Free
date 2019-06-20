#include "../head/PathMap.h"

PathMap::PathMap()
{
    //se non è stato inserito nessun percorso, la matrice è vuota...
    map.resize(1);
}

void PathMap::add(const int &i, const int &j, ALLEGRO_COLOR color)
{
   //creiamo un percorso...
   pair<int, int> coord(i, j);

    //aggiunge la coordinata...
    if(find(map.back().begin(), map.back().end(), coord) == map.back().end())
    {
        map.back().push_back(coord);
        cout << coord.first << " - " << coord.second << endl;
    }

    //aggiunge alla lista dei colori...
    colors.push_back(color);
    unique(colors.begin(), colors.end()); 
}