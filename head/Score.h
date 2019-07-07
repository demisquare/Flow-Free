#ifndef SCORE_H
#define SCORE_H

using namespace std;

class Score
{
    private:
    unsigned moves = 0;
    unsigned remainingMoves = 0;

    unsigned timeLeft = 60;

    public:
    unsigned getMoves()const{return moves;}
    unsigned getRemainingMoves()const{return remainingMoves;}
    void setRemainingMoves(unsigned m){remainingMoves = m;}

    unsigned getTimeLeft()const{return timeLeft;}

    void addMoves() {moves++;}

    void tick()
    {
        if(timeLeft > 0)
            timeLeft--;
    }

    bool timeElapsed()const{return timeLeft == 0;}
    bool noMoreMoves()const{return moves > remainingMoves;}
};

#endif