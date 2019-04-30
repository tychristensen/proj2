//
// Created by ms2 on 3/17/2019.
//

#include "BetaPlayer.h"

//------------------------------------------------------------------------
// Name:  BetaPlayer::getBet()
//
// Description: Get's a bet from the beta AI player.
//
// Arguments:
//	Hand opponent - visible portion of hand of the opponent
//  BetHistory bh - History of current betting round
//  int bet2player - current bet to the player
//  bool canraise - if true, the player may raise, if false he may only call
//  int pot - current size of the pot
//
// Modifies:  none
//
// Returns: the bet amount including the amount to to the player (i.e. the amount
//  to be put in the pot.
//  -1 is a command to quit (only comes from the human player)
//  0 is a fold IF there is a bet to the player (otherwise, it's just a call)
//
//--------------------------------------------------------------------
int BetaPlayer::getBet(Hand opponent, BetHistory bh, int bet2player, bool canraise, int pot)
{

    srand(time(nullptr));
    int bet = 0 ;
    int delta = m_hand.evaluate() - opponent.evaluate() ;
    int nbets = bh.getCount() ;
    int ncards = m_hand.getCount() ;
    //The variable hand factor measures the value of beta's hand versus the opponents hand
    int handFactor = m_hand.evaluate() / opponent.evaluate() * 100;
    //The chip ratio helps take into account the chip advantage or disadvantage
    //This is a ratio of our chips over the total amount of chips owned by the beta
    //and its opponent
    int chipRatio = m_chips - (2000 - m_chips - pot) / m_chips + (2000 - m_chips - pot);
    if( ncards < 5 ) {
        if( nbets == 0 ) {
            if( delta > 10 ) {
                bet = (rand() % 6) + 5;
            } else if( delta > 5 ) {
                bet = (rand() % 6);
            } else if( delta > 0 ) {
                bet = (rand() % 3);
            } else {
                bet = 0 ;
            }
        } else {
            int pot_factor = pot / 10 ;
            if( bet2player == 0 ) {
                if( delta > 5 - pot_factor ) {
                    bet = (rand() % 6) + 5;
                } else if( delta > -pot_factor ) {
                    bet = (rand() % 3);
                } else {
                    bet = 0 ;
                }
            } else if( bet2player < 1 + 2*pot_factor ) {
                if( delta > 8 - pot_factor ) {
                    bet = bet2player + (rand() % 6) + 5;
                } else if( delta > -2 - pot_factor ) {
                    bet = bet2player + (rand() % 3);
                } else if( delta > -4 - pot_factor ) {
                    bet = bet2player ;
                } else {
                    bet = 0 ;
                }
            } else {
                if( delta > 10 - pot_factor ) {
                    bet = bet2player + (rand() % 6) + 5;
                } else if( delta > -pot_factor ) {
                    bet = bet2player + (rand() % 3);
                }
                else if( delta > -2 - pot_factor ) {
                    bet = bet2player ;
                } else {
                    bet = 0 ;
                }
            }
        }
    } else {
        if( nbets == 0 ) {
            if( delta > 10 ) {
                bet = (rand() % 6) + 5;
            } else if( delta > 5 ) {
                bet = 5 ;
            }
            else {
                bet = 0 ;
            }
        } else {
            int pot_factor = pot / 10 ;
            if( bet2player == 0 ) {
                if( delta > 10 - pot_factor ) {
                    bet = 10 ;
                } else {
                    bet = 0 ;
                }
            } else if( bet2player < 1 + 2*pot_factor ) {
                if( delta > 6 - pot_factor ) {
                    bet = bet2player + 10 ;
                } else if( delta > 2 ) {
                    bet = bet2player ;
                } else {
                    bet = 0 ;
                }
            } else {
                if( delta > 8 - pot_factor ) {
                    bet = bet2player + 10 ;
                } else if( delta > 4 ) {
                    bet = bet2player ;
                } else {
                    bet = 0 ;
                }
            }
        }
    }
    if( !canraise && bet > bet2player ) {
        bet = bet2player ;
    }

    return bet ;

}  // end BetaGetBet
