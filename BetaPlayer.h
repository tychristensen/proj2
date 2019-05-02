//
// Created by ms2 on 3/17/2019.
//

#ifndef POKERPT1_BETAPLAYER_H
#define POKERPT1_BETAPLAYER_H

#include "Player.h"
#include <cstdlib>
#include <time.h>
#include <random>

class BetaPlayer : public Player {
public:
    BetaPlayer( int id, int chips ) : Player( id, chips ){ } ;

    int getBet(Hand opponent, BetHistory bh, int bet2player, bool canraise, int pot) ;

};


#endif //POKERPT1_BETAPLAYER_H
