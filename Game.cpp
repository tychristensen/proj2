//========================================================
//
//  File Name:   Game.cpp
//
//  Author:  Mark Baldwin
//
//  Course and Assignment:   CSCI477 Project 2 
//
//  Description:  base class for the game driver
//
//=========================================================
#include "Game.h"
#include "HumanPlayer.h"
#include "AlphaPlayer.h"
#include "BetaPlayer.h"

#include <stdlib.h> 
#include <iostream>
#include <assert.h>

using namespace std;


//------------------------------------------------------------------------
// Name:  Game::Game()
//
// Description: Class Constructor
//
// Arguments: none
//
// Modifies:  Sets up the game
// 
// Returns: none
//
//--------------------------------------------------------------------
Game::Game()
{
    string cardNames[] = { "Ace of ", "Two of ", "Three of ", "Four of ", "Five of ", "Six of ", "Seven of ",
                           "Eight of ", "Nine of ", "Ten of ", "Jack of ", "Queen of ", "King of " } ;
    string cardSuits[] = { "Spades", "Hearts", "Diamonds", "Clubs" };

    for( int i = 0 ; i < 13 ; i++ ) {
		for (int j = 0; j < 4; j++) {
			if (i < 9) {
				m_deck[13 * j + i].setCard(cardNames[i] + cardSuits[j], i + 1);
			} else {
				m_deck[13 * j + i].setCard(cardNames[i] + cardSuits[j], 10);
			}
		}
	}
} // end Game



//------------------------------------------------------------------------
// Name:  Game::playGame()
//
// Description: Play a full game
//
// Arguments: 
//	playerType - type of player for player 0
//	playerType - type of player for player 1
//	int & - returns final chip win/lose for player 0
//	int & - returns final chip win/lose for player 1
//	bool - report flag - if on, prints activity
//
// Modifies:  full game
// 
// Returns: returns true if someone wants to quit
//
//--------------------------------------------------------------------
bool Game::playGame(PlayerType p1, PlayerType p2, int &chips1, int &chips2, bool reportflag)
{
	Player *player0, *player1 ;

	// create the players
	switch( p1 ) {
		case HUMAN:
			player0 = new HumanPlayer( 0, START_CHIPS ) ;
			break ;
		case ALPHA:
			player0 = new AlphaPlayer( 0, START_CHIPS ) ;
			break ;
		case BETA:
			player0 = new BetaPlayer( 0, START_CHIPS ) ;
			break ;
	}

	switch( p2 ) {
		case HUMAN:
			player1 = new HumanPlayer( 1, START_CHIPS ) ;
			break ;
		case ALPHA:
			player1 = new AlphaPlayer( 1, START_CHIPS ) ;
			break ;
		case BETA:
			player1 = new BetaPlayer( 1, START_CHIPS ) ;
			break ;
	}

	m_reportFlag = reportflag ;
	m_pot = 0 ;

	// we play 20 hands alternating the players
	for( int index = 0 ; index < 10 ; index++ )
	{
		bool quit = playHand(player0, player1) ;

		// check to see if someone wants to quit
		if( quit == true )
		{
			return true ;
		}  // end if

		quit = playHand(player1, player0) ;

		// check to see if someone wants to quit
		if( quit == true )
		{
			return true ;
		}  // end if
	}

	// if there is anything left in the pot, distribute equally 
	if( m_pot > 0 )
	{
		player0->addChips( m_pot / 2 ) ;
		player1->addChips( m_pot / 2 ) ;
	}

	// give results
	if( m_reportFlag )
	{
		cout << " Game completed.  Player 0 had " << player0->getChips() << " chips and Player 1 had " << player1->getChips() << " chips." << endl ;
	}

	chips1 = player0->getChips() - START_CHIPS ;
	chips2 = player1->getChips() - START_CHIPS ;

	// clean up memory
	delete player0 ;
	delete player1 ;
	
	return false ;
}


//------------------------------------------------------------------------
// Name:  Game::playHand()
//
// Description: Play a game hand
//
// Arguments: 
//	Player p1 - First player to bet
//	Player p2 - Second player to bet
//
// Modifies:  
// 
// Returns: bool - if true, someone wants to quit the game
//
//--------------------------------------------------------------------
bool Game::playHand(Player *p1, Player *p2)
{
	bool quit_flag = false ;

	// informational print
	if( m_reportFlag )
	{
		cout << "New hand, Player " << p1->getId() << " starts first." << endl ;
	}

	// set up the hand
	shuffleDeck() ;

	// feed the pot at the start
	m_pot += BUY_IN * 2 ;
	p1->addChips( -BUY_IN ) ;
	p2->addChips( -BUY_IN ) ;


	// deal the first round of three cards to each player
	int current_card = 0 ;

	p1->clearHand();
	p1->dealCard( m_deck[current_card++]) ;
	p1->dealCard( m_deck[current_card++]) ;
	p1->dealCard( m_deck[current_card++]) ;

	p2->clearHand();
	p2->dealCard( m_deck[current_card++]) ;
	p2->dealCard( m_deck[current_card++]) ;
	p2->dealCard( m_deck[current_card++]) ;

	// loop doing a betting round, then deal new cards
	for( int round = 0 ; round < 3 ; round++ )
	{
		// bet a round, if someone folded, finish
		int result = betRound(p1, p2) ;

		// check if human wants to quit
		if( result == -2 )
		{
			quit_flag = true ;
			break ;
		}
		
		// if someone folded
		if( result >= 0 )
		{
			
			if( m_reportFlag )
			{
				cout << "Player " << (1-result) << " folded.   The pot was " << m_pot << "." << endl ;  
			} // end if
			
			// payout the pot 
			if( result == p1->getId() )
			{
				p1->addChips( m_pot ) ;
			}
			else
			{
				p2->addChips( m_pot ) ;
			}
			// clear the pot
			m_pot = 0 ;   

			break ;
		}

		// check if we have another round
		if( round < 2 )
		{
			p1->dealCard( m_deck[current_card++]) ;
			p2->dealCard( m_deck[current_card++]) ;
		}
		else  // showdown, we complete the hand
		{
			// see who won
			int hv1 = p1->getHand().evaluate() ;
			int hv2 = p2->getHand().evaluate() ;

			if( hv1 > hv2 )
			{
				if( m_reportFlag )
				{
					cout << " Player " << p1->getId() << " won the hand with a pot of " << m_pot << endl ;
				} // end if
				p1->addChips( m_pot ) ;
				m_pot = 0 ;
			}
			else if(hv2 > hv1 )
			{
				if( m_reportFlag )
				{
					cout << " Player " << p2->getId() << " won the hand with a pot of " << m_pot << endl  ;
				} // end if
				p2->addChips( m_pot ) ;
				m_pot = 0 ;
			}
			else // tie
			{
				if( m_reportFlag )
				{
					cout << " The hand was a tie.   The pot is carried over to the next hand." << endl  ;
				} // end if
			}// end if

		} // end if

	}  // end for


	if( m_reportFlag )
	{
		if( p1->getId() == 0 )
		{
			cout << "Current chips:  Player 0 - " << p1->getChips() << "  Player 1 - " << p2->getChips() << endl << endl ;
		}
		else
		{
			cout << "Current chips:  Player 0 - " << p2->getChips() << "  Player 1 - " << p1->getChips() << endl << endl ;
		}
	}  // end if

	return quit_flag ;
}  // end playHand

//------------------------------------------------------------------------
// Name:  Game::betRound()
//
// Description: Process a betting round
//
// Arguments: 
//	Player p1 - First player to bet
//	Player p2 - Second player to bet
//
// Modifies:  
//	pot
//	players chips
// 
// Returns: 
//	int result:  -1 means both players in game, 
//				  0 or 1 means that player won (other folded) 
//				  -2 means human player wants to quit
//
//--------------------------------------------------------------------
int Game::betRound(Player *p1, Player *p2)
{
	Bet bet ;
	int bet2player = 0 ;  // bet to the player
	int n_rounds = 0 ;
	bool canraise = true ;
	int raises = 0 ;
	
	// create visible hands of the opponents
	Hand firsthand = p1->getHand().getVisible() ;
	Hand secondhand = p2->getHand().getVisible() ;

	// initialize the history
	m_betHistory.clearHistory() ;

	// loop till betting is done
	while( true ) 
	{
		// process first player
		assert( m_pot > 0 ) ;
		Bet bet1st( p1->getBet(secondhand, m_betHistory, bet2player, canraise, m_pot), p1->getId() ) ;

		// check to see if human wants to quit
		if( bet1st.getAmount() == -1 )
		{
			return -2 ;
		}

		m_betHistory.addBet(bet1st) ;

		// if did not call or raise
		if( bet1st.getAmount() < bet2player )
		{
			return p2->getId() ;
		}  // end if

		// adjust the pot
		m_pot += bet1st.getAmount() ;
		p1->addChips( -bet1st.getAmount() ) ;
		bet2player = bet1st.getAmount() - bet2player ;
		
		// if a call
		if( bet2player == 0 )
		{
			break ;
		}
		else
		{ 
			raises++ ;
			if( raises >= MAX_NUMBER_RAISES )  // check the raises
			{
				canraise = false ;
			}

		}  // end if

		// process second player
		assert( m_pot > 0 ) ;
		Bet bet2nd( p2->getBet(firsthand, m_betHistory, bet2player, canraise, m_pot), p2->getId() ) ;
		
		// check to see if human wants to quit
		if( bet2nd.getAmount() == -1 )
		{
			return -2 ;
		}

		m_betHistory.addBet( bet2nd ) ;

		// if did not call
		if( bet2nd.getAmount() < bet2player )
		{
			return p1->getId() ;
		}  // end if

		// adjust the pot
		m_pot += bet2nd.getAmount() ;
		p2->addChips( -bet2nd.getAmount() ) ;
		bet2player = bet2nd.getAmount() - bet2player ;

		// if a call
		if( bet2player == 0 )
		{
			break ;
		}
		else
		{ 
			raises++ ;
			if( raises >= MAX_NUMBER_RAISES )  // check the raises
			{
				canraise = false ;
			}

		}  // end if

	} // end while

	return -1 ; // no one won betting
}  // end betRound

//------------------------------------------------------------------------
// Name:  Game::shuffleDeck()
//
// Description: Randomly shuffle the deck
//
// Arguments: none
//
// Modifies:  m_deck
// 
// Returns: none
//
// Comments:
//   This works by randomly swapping two cards a large number of times, there
//   are other equally good methods like putting the cards in a queue, and then
//   randomly popping them off and putting them in the deck.
//--------------------------------------------------------------------
void Game::shuffleDeck()
{
	Card tcard ;
	int c1, c2;

	// basically we swap 2 cards randomly in the deck 1000 times
	for( int i = 0 ; i < 1000 ; i++ )
	{
		// cards to be swapped
		c1 = rand() % 52 ;
		c2 = rand() % 52 ;

		tcard = m_deck[c1] ;
		m_deck[c1] = m_deck[c2] ;
		m_deck[c2] = tcard ;
	} // end for
} // end shuffleDeck

