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
    unsigned getMoves()const;
    unsigned getRemainingMoves()const;
    void setRemainingMoves(unsigned m);

    unsigned getTimeLeft()const;

    void addMoves();

    void tick();

    bool timeElapsed()const;
    bool noMoreMoves()const;
};

#endif