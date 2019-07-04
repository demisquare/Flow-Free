#ifndef SCORE_H
#define SCORE_H

using namespace std;

class Score
{
    private:
    unsigned moves = 0;
    unsigned remainingMoves = 5;

    unsigned timeLeft = 60;

    ALLEGRO_TIMER* timer;


    public:
    Score():timer(NULL)
    {
        timer = al_create_timer(1.0);

        if(!timer)
        {
          cerr << "failed to create timer!\n";
          exit(-1);
        }
    }

    unsigned getMoves()const{return moves;}
    unsigned getRemainingMoves()const{return remainingMoves;}

    unsigned getTimeLeft()const{return timeLeft;}

    void addMoves() {moves++;}

    void tick()
    {
        if(timeLeft > 0)
            timeLeft--;
    }

    bool timeElapsed()const{return timeLeft == 0;}
    bool noMoreMoves()const{return moves == remainingMoves;}
};

#endif