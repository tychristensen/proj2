//
// Created by ms2 on 3/17/2019.
//

#ifndef POKERPT1_ALPHAPLAYER_H
#define POKERPT1_ALPHAPLAYER_H

#include "Player.h"

class AlphaPlayer : public Player {
public:
    AlphaPlayer( int id, int chips ) : Player( id, chips ){ } ;

    int getBet(Hand opponent, BetHistory bh, int bet2player, bool canraise, int pot) ;

};


#endif //POKERPT1_ALPHAPLAYER_H
