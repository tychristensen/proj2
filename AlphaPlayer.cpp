//
// Created by ms2 on 3/17/2019.
//

#include "AlphaPlayer.h"

//------------------------------------------------------------------------
// Name:  Player::AlphaGetBet()
//
// Description: Get's a bet from the alpha AI player.
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
int AlphaPlayer::getBet(Hand opponent, BetHistory bh, int bet2player, bool canraise, int pot)
{
    int bet = 0 ;   // the bet we develop

    // compare the hands
    int delta = m_hand.evaluate() - opponent.evaluate() ;

    // number of bets in round
    int nbets = bh.getCount() ;

    // number of cards in hand (to find out if this is the last round)
    int ncards = m_hand.getCount() ;

    // rule 2
    if( ncards < 5 )
    {
        // rule 2a
        if( nbets == 0 )
        {
            if( delta > 10 )
            {
                bet = 10 ;
            }
            else if( delta > 5 )
            {
                bet = 5 ;
            }
            else if( delta > 0 )
            {
                bet = 1 ;
            }
            else
            {
                bet = 0 ;
            } // end if
        }
            // rule 2b
        else
        {
            int pot_factor = pot / 10 ;

            // if bet2player is 0, that means the other player called
            // rule 2bii
            if( bet2player == 0 )
            {
                if( delta > 5 - pot_factor )
                {
                    bet = 10 ;
                }
                else if( delta > -pot_factor )
                {
                    bet = 1 ;
                }
                else
                {
                    bet = 0 ;  // this is a call because the bet to the player was a call
                } // endif
            }
                // rule 2biii
            else if( bet2player < 1 + 2*pot_factor )
            {
                if( delta > 8 - pot_factor )
                {
                    bet = bet2player + 10 ;  // this is a raise of 10
                }
                else if( delta > -2 - pot_factor )
                {
                    bet = bet2player + 1 ; // this is a raise of 1
                }
                else if( delta > -4 - pot_factor )
                {
                    bet = bet2player ;  // this is a call
                }
                else
                {
                    bet = 0 ;  // this is a fold
                }  // endif
            }
                // rule 2biv
            else
            {
                if( delta > 10 - pot_factor )
                {
                    bet = bet2player + 10 ;  // this is a raise of 10
                }
                else if( delta > -pot_factor )
                {
                    bet = bet2player + 1 ; // this is a raise of 1
                }
                else if( delta > -2 - pot_factor )
                {
                    bet = bet2player ;  // this is a call
                }
                else
                {
                    bet = 0 ;  // this is a fold
                } // endif
            } // endif
        } // endif
    }
        // rule 3
    else
    {
        // rule 3a
        if( nbets == 0 )
        {
            if( delta > 10 )
            {
                bet = 10 ;
            }
            else if( delta > 5 )
            {
                bet = 5 ;
            }
            else
            {
                bet = 0 ;
            } // end if
        }
            // rule 3b
        else
        {
            int pot_factor = pot / 10 ;

            // if bet2player is 0, that means the other player called
            // rule 3bii
            if( bet2player == 0 )
            {
                if( delta > 10 - pot_factor )
                {
                    bet = 10 ;
                }
                else
                {
                    bet = 0 ;  // this is a call because the bet to the player was a call
                } // endif
            }
                // rule 3biii
            else if( bet2player < 1 + 2*pot_factor )
            {
                if( delta > 6 - pot_factor )
                {
                    bet = bet2player + 10 ;  // this is a raise of 10
                }
                else if( delta > 2 )
                {
                    bet = bet2player ;  // this is a call
                }
                else
                {
                    bet = 0 ;  // this is a fold
                }  // endif
            }
                // rule 3biv
            else
            {
                if( delta > 8 - pot_factor )
                {
                    bet = bet2player + 10 ;  // this is a raise of 10
                }
                else if( delta > 4 )
                {
                    bet = bet2player ;  // this is a call
                }
                else
                {
                    bet = 0 ;  // this is a fold
                } // endif
            } // endif
        } // endif
    } // endif

    // if we cannot raise, the bet cannot be greater than bet2player
    if( canraise == false &&
        bet > bet2player )
    {
        bet = bet2player ;
    }  // endif

    return bet ;

}  // end AlphaGetBet
