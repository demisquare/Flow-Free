#include "../head/PathMap.h"

PathMap::PathMap()
{
    //se non è stato inserito nessun percorso, la matrice è vuota...
    map.resize(1);
}

pair<int, int> PathMap::getLastCoords(){return map.back().back();}

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
    if(find(colors.begin(), colors.end(), color) == colors.end())
    {
        colors.push_back(color);
        //cout << "colors: " << colors.size() << endl;
    }
}

bool PathMap::isClosed(const GameMap &gameMap, vector<pair<int,int> > path) const
{
    cout << ((gameMap.getObj(path.front().first, path.front().second)->getType()
         ==   gameMap.getObj(path.back().first, path.back().second)->getType() == BALL)

         && (gameMap.getObj(path.front().first, path.front().second)->getColor()
         ==  gameMap.getObj(path.back().first, path.back().second)->getColor())) << endl;

    //un percorso è chiuso se gli estremi di un percorso sono Ball e se hanno lo stesso colore...
    return ((gameMap.getObj(path.front().first, path.front().second)->getType()
        ==   gameMap.getObj(path.back().first, path.back().second)->getType() == BALL)

        && (gameMap.getObj(path.front().first, path.front().second)->getColor()
        ==  gameMap.getObj(path.back().first, path.back().second)->getColor()));
}

//condizione di vittoria: tutti i percorsi sono chiusi e la mappa è piena...
bool PathMap::victory(const GameMap &gameMap) const
{
    //se la mappa è piena...
    if(gameMap.isFull())
    {
        //se tutti i percorsi sono chiusi...
        for(unsigned i = 0; i < map.size(); i++)
        if(!isClosed(gameMap, map.at(i)))
            return false;
    }
    return true;
    
}