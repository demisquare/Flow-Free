#include "../head/PathMap.h"

pair<int, int> PathMap::getLastCoords(){return currentPath.back();}

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


  unsigned x1 = currentPath.back().first;
  unsigned y1 = currentPath.back().second;

  unsigned x2 = coord.first;
  unsigned y2 = coord.second;

  return
    !((x2 == x1+1 && y2 == y1+1)
    ||(x2 == x1+1 && y2 == y1-1)
    ||(x2 == x1-1 && y2 == y1+1)
    ||(x2 == x1-1 && y2 == y1-1));
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

//resituisce il percorso che contiene la coordinata...
vector<pair<int, int> > PathMap::findPath(pair<int, int> coord)
{
    vector<pair<int, int> > found;
    if(map.empty())
        return found;
    else
    {
        for(auto path:map)
            if(find(path.begin(), path.end(), coord) != path.end())
                found = path;
        return found;
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
        &&  adj(coord))
        {
            currentPath.push_back(coord);
            gm.addPath(coord.first, coord.second, color);
            cout << coord.first << " - " << coord.second << endl;
            ok = true;
        }  

        //chiusura del percorso...
        if(isClosed(currentPath) && isUnique())
        {
            cout << "closed!" << endl;

            map.push_back(currentPath);
            cout << "map: " << map.size() << endl;
            currentPath.clear();    
            ok = true;
        }
    }
    return ok;
}

//rimuove un percorso dalla mappa...
/*bool PathMap::remove(const int &i, const int &j, ALLEGRO_COLOR color)
{
   bool ok = false;
   //creiamo una coordinata...
   pair<int, int> coord(i, j);

   //cerco il percorso
   vector<pair<int, int> > toRemove=find(coord);
   if(!color==toRemove.getColor())
    toRemove.setColor(BLACK);

   
}*/
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