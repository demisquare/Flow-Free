#include "../head/PathMap.h"

pair<int, int> PathMap::getLastCoords(){return currentPath.back();}

GameMap& PathMap::getLogic(){return gm;}

void PathMap::load(const int& lvl)
{
    gm.load(lvl);
}

//verifica se è la coordinata è stata già inserita...
bool PathMap::isSigned(pair<int, int> coord)
{
    if(map.empty())
        return false;
    else
    {
    bool ok = false;
        for(auto path:map)
            if(find(path.begin(), path.end(), coord) != path.end())
                ok = true;
    return ok;
    }
}

//verifica se il percorso è stato già inserito...
bool PathMap::isUnique()
{
    if(map.empty())
        return true;
    else
    {
        bool unique = true;
        for(auto path:map)
            for(auto p:currentPath)
                if(find(path.begin(), path.end(), p) != path.end())
                    unique = false;
        return unique;
    }
}

void PathMap::add(const int &i, const int &j, ALLEGRO_COLOR color)
{
   //creiamo un percorso...
   pair<int, int> coord(i, j);
    
    if(!isSigned(coord))
    {
        //aggiunge la coordinata...
        if(find(currentPath.begin(), currentPath.end(), coord) == currentPath.end())
        {
            currentPath.push_back(coord);
            cout << coord.first << " - " << coord.second << endl;
        }  
    
        if(isClosed(currentPath) && isUnique())
        {
            cout << "closed!" << endl;

            map.push_back(currentPath);
            cout << "map: " << map.size() << endl;
            currentPath.clear();            
        }
    }
}

vector<vector<pair<int, int> > >& PathMap::getPaths(){return map;}

vector<pair<int, int> >& PathMap::getCurrentPath(){return currentPath;}


bool PathMap::isClosed(vector<pair<int,int> > path)
{
    //un percorso è chiuso se gli estremi di un percorso sono Ball e se hanno lo stesso colore...
    return ((gm.getLogicObj(path.front().first, path.front().second)->getType() == BALL
        &&   gm.getLogicObj(path.back().first, path.back().second)->getType() == BALL)

        && (gm.getLogicObj(path.front().first, path.front().second)->getColor()
        ==  gm.getLogicObj(path.back().first, path.back().second)->getColor()) && path.size() >= 2);
}

//condizione di vittoria: tutti i percorsi sono chiusi e la mappa è piena...
bool PathMap::victory()
{
    return (map.size() == gm.getColors()) && gm.isFull();
}