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

vector<vector<pair<int, int> > > PathMap::getPaths(){return map;}

void PathMap::draw(const GameMap& gm)
{    
    //scorri per tutti i percorsi...
    for(auto path: map)    
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
                             color, 20); 
            }
        }
}

bool PathMap::isClosed(const GameMap &gm, vector<pair<int,int> > path) const
{
    cout << ((gm.getObj(path.front().first, path.front().second)->getType()
         ==   gm.getObj(path.back().first, path.back().second)->getType() == BALL)

         && (gm.getObj(path.front().first, path.front().second)->getColor()
         ==  gm.getObj(path.back().first, path.back().second)->getColor())) << endl;

    //un percorso è chiuso se gli estremi di un percorso sono Ball e se hanno lo stesso colore...
    return ((gm.getObj(path.front().first, path.front().second)->getType()
        ==   gm.getObj(path.back().first, path.back().second)->getType() == BALL)

        && (gm.getObj(path.front().first, path.front().second)->getColor()
        ==  gm.getObj(path.back().first, path.back().second)->getColor()));
}

//condizione di vittoria: tutti i percorsi sono chiusi e la mappa è piena...
bool PathMap::victory(const GameMap &gm) const
{
    //se la mappa è piena...
    if(gm.isFull())
    {
        //se tutti i percorsi sono chiusi...
        for(unsigned i = 0; i < map.size(); i++)
        if(!isClosed(gm, map.at(i)))
            return false;
    }
    return true;
    
}