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

    random_device rd;
    int bet = 0 ;
    int delta = m_hand.evaluate() - opponent.evaluate() ;
    int nbets = bh.getCount() ;
    int ncards = m_hand.getCount() ;
    int potFactor = pot / 10 ;
    //The variable hand factor measures the value of beta's hand versus the opponents hand
    double handFactor = 10.0 * ((double) m_hand.evaluate()) / opponent.evaluate();



    if (handFactor <= 3.0) {
        bet = 0;
    } else if (handFactor <= 10.0) {
        if(rd() % 1000 < 1) {
            //Bluff
            bet = bet2player + 10;
        } else {
            bet = bet2player + 0;
        }
    } else if (handFactor <= 12.0) {
        if(rd() % 1000 < 1) {
            //Bluff
            bet = bet2player + 10;
        } else {
            bet = bet2player + 3;
        }
    } else if (handFactor <= 15.0) {
        bet = bet2player + 5;
    } else {
        bet = bet2player + 10;
    }

    if( !canraise && bet > bet2player ) {
        bet = bet2player ;
    }

    return bet ;

}  // end BetaGetBet
