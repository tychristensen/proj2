//========================================================
//
//  File Name:   HumanPlayer.cpp
//
//  Author:  Mark Baldwin
//
//  Course and Assignment:   CSCI477 Project 2
//
//  Description:  human interface for getting bet
//
//=========================================================


#include "HumanPlayer.h"
#include <iostream>

using namespace std ;

//------------------------------------------------------------------------
// Name:  HumanPlayer::getBet()
//
// Description: Get's a bet from the human player.
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
int HumanPlayer::getBet(Hand opponent, BetHistory bh, int bet2player, bool canraise, int pot)
{
    Card card ;

    // first we tell the player the situation, then ask for the bet
    cout << "**********  Player " << m_id << " **********" << endl ;
    cout << "The pot has " << pot << " chips." << endl ;
    cout << "Your hand: " << endl ;

    int count = m_hand.getCount() ;
    card = m_hand.getCard(0) ;  // get the facedown card

    cout << "    " << card.getName() << " (card is facedown) " << endl ;

    for( int index = 1 ; index < count ; index++ )
    {
        card = m_hand.getCard(index) ;  // get the facedown card
        cout << "    " << card.getName() << endl ;
    }

    cout << "Opponents hand showing: " << endl ;

    // now display the opponents hand
    count = opponent.getCount() ;
    for( int index = 0 ; index < count ; index++ )
    {
        card = opponent.getCard(index) ;
        cout << "    " << card.getName() << endl ;
    }  // end for

    count = bh.getCount() ;

    // display the bet history
    if( count > 0 )
    {
        cout << endl << "Bet History: " << endl ;

        for( int index = 0 ; index < count ; index++ )
        {
            cout << " Player: " <<  bh.getBet(index).getPlayer() << "  Bet: " << bh.getBet(index).getAmount() << endl ;
        }  // end for
    }

    // now get the humans bet
    int betv ;
    while( true )
    {
        int maxPBet = bet2player ;  // the maximum bet the player may make

        // if we can raise, the maximum bet is increased
        if( canraise )
        {
            maxPBet += MAX_BET ;
        }

        cout << endl << "The bet to you is " << bet2player << endl ;

        // is there a bet to the player?
        if( bet2player > 0 )
        {
            cout << "Bet 0 to fold or bet " << bet2player << " to " << maxPBet << ".  Bet -1 to quit." << endl ;
        }
        else
        {
            cout << "Bet 0 to call or bet up to " << maxPBet << " to raise.  Bet -1 to quit." << endl ;
        }
        cout << "What is your bet? " ;
        cin >> betv ;

        // flush the cin buffer
        cin.clear() ;
        fflush(stdin);

        // good bet or request to quit
        if( betv == 0 ||
            betv == -1 ||
            (betv >= bet2player && betv <= maxPBet ))
        {
            break ;
        } // endif
    } // end while

    cout << endl << endl ;

    return betv ;
}  // end HumanGetBet
