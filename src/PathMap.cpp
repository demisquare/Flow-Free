#include "../head/PathMap.h"

GameMap& PathMap::getLogic(){return gm;}

void PathMap::load(const int& lvl)
{
    gm.load(lvl);
}

//verifica se due coordinate sono adiacenti...
bool PathMap::adj(pair<int, int> coord)
{
  if(currentPath.empty())
    return true;

  int x1 = currentPath.back().first;
  int y1 = currentPath.back().second;

  int x2 = coord.first;
  int y2 = coord.second;

  return
       (abs(x1 - x2) == 1 && y1 == y2)
    || (abs(y1 - y2) == 1 && x1 == x2);
}

//verifica se la coordinata è stata già inserita...
bool PathMap::isSigned(pair<int, int> coord)
{
    bool ok = false;

    if(!map.empty())
        for(auto path:map)
            if(find(path.begin(), path.end(), coord) != path.end())
                ok = true;
    return ok;
    
}

//restituisce il percorso che contiene la coordinata...
vector<pair<int, int> > PathMap::findPath(pair<int, int> coord)
{
    vector<pair<int, int> > not_found;

    if(!map.empty())
        for(auto path:map)
            if(find(path.begin(), path.end(), coord) != path.end())
                return path;
    
    return not_found;
}

//verifica se il percorso è stato già inserito...
bool PathMap::isUnique()
{   
    bool unique = true;

    if(!map.empty())
        for(auto path:map)
            for(auto p:currentPath)
                if(find(path.begin(), path.end(), p) != path.end())
                    unique = false;
    return unique;
    
}

//aggiunge un percorso alla mappa...
bool PathMap::add(const int &i, const int &j, ALLEGRO_COLOR color)
{
   bool ok = false;
   //creiamo una coordinata...
   pair<int, int> coord(i, j);
    
    //se non è stata segnata...
    if(!isSigned(coord))
    {
        //aggiunge la coordinata...
        if(find(currentPath.begin(), currentPath.end(), coord) == currentPath.end()
        &&  adj(coord) && !isClosed(currentPath))
        {
            currentPath.push_back(coord);
            gm.addPath(coord.first, coord.second, color);
            ok = true;
        }  

        //accorcia il percorso corrente se si interseca da solo...
        else if(!currentPath.empty() && coord != currentPath.back()
        && gm.getLogicObj(coord.first, coord.second)->getType()!=BALL)
            shrink(coord);
    }
    //se è stata già segnata...
    else
        //elimina intersezioni tra currentPath e altri percorsi nella mappa...
        remove(i, j);
    
    return ok;
}

//rimuove un percorso attraverso una sua coordinata...
bool PathMap::remove(const int &i, const int &j)
{
    //creiamo una coordinata...
    pair<int, int> coord(i, j);

    //individua il percorso da eliminare...
    vector<pair<int, int> > path = findPath(coord);

    //se elimina il percorso...
    if(removePath(path))
    {
        //elimina il percorso dalla mappa...
        map.erase(find(map.begin(), map.end(), path));

        return true;
    }
    return false;
}

//chiude il percorso corrente e lo aggiunge alla mappa...
bool PathMap::closePath()
{
    if(isClosed(currentPath) && isUnique())
    {
        map.push_back(currentPath);
        currentPath.clear();    
        return true;
    }
    return false;
}

//rimuove un percorso selezionato...
bool PathMap::removePath(vector<pair<int, int> >& path)
{
    if(!path.empty())
    {
        for(auto coord : path)
            gm.removePath(coord.first, coord.second);
        
        path.clear();
        return true;
    }
    return false;
}

//accorcia il percorso corrente...
void PathMap::shrink(pair<int, int> coord)
{
   //segna la posizione di coord con un iteratore...
   vector<pair<int, int> >::iterator it = find(currentPath.begin(), currentPath.end(), coord);

   //scorri da end ad it e fai pop_back...
   while(currentPath.end() != it)
   {
        gm.removePath(currentPath.back().first, currentPath.back().second);
        currentPath.pop_back();
   }

}
vector<vector<pair<int, int> > >& PathMap::getPaths(){return map;}

vector<pair<int, int> >& PathMap::getCurrentPath(){return currentPath;}

//verifica se un percorso è chiudibile...
bool PathMap::isClosed(vector<pair<int,int> > path)
{
    if(path.empty())
        return false;
    //un percorso è chiuso se gli estremi di un percorso sono Ball e se hanno lo stesso colore...
    return ((gm.getLogicObj(path.front().first, path.front().second)->getType() == BALL
        &&   gm.getLogicObj(path.back().first, path.back().second)->getType() == BALL)

        &&  (gm.getLogicObj(path.front().first, path.front().second)->getColor()
        ==   gm.getLogicObj(path.back().first, path.back().second)->getColor())

        &&   path.size() >= 2);
}

//condizione di vittoria: tutti i percorsi sono chiusi e la mappa è piena...
bool PathMap::victory()
{
    return (map.size() == gm.getColors()) && gm.isFull();
}