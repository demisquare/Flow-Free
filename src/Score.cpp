#include "../head/Score.h"

unsigned Score::getMoves()const{return moves;}
unsigned Score::getRemainingMoves()const{return remainingMoves;}
void Score::setRemainingMoves(unsigned m){remainingMoves = m;}

unsigned Score::getTimeLeft()const{return timeLeft;}

void Score::addMoves() {moves++;}

void Score::tick()
{
    if(timeLeft > 0)
        timeLeft--;
}
bool Score::timeElapsed()const{return timeLeft == 0;}
bool Score::noMoreMoves()const{return moves > remainingMoves;}