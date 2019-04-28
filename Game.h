//========================================================
//
//  File Name:   Game.h
//
//  Author:  Mark Baldwin
//
//  Course and Assignment:   CSCI477 Project 2 
//
//  Description:  Declaration of the game class
//
//=========================================================

#pragma once

#include "Hand.h"
#include "BetHistory.h"
#include "Player.h"

//===================================================================
//
//  Class: Game
//
//  Contains the data describing a player in the game 
//
//===================================================================
class Game
{
public:
	Game();

	// play a single game
	bool playGame(PlayerType p1, PlayerType p2, int &chips1, int &chips2, bool reportflag) ;

private:
	bool playHand(Player *p1, Player *p2) ;  // play a hand
	void shuffleDeck() ;
	int betRound(Player *p1, Player *p2) ;  // do a betting round

	Card m_deck[52] ;  // the card deck
	int m_pot ;			// the current pot
	bool m_reportFlag ; // print activity if on

	BetHistory m_betHistory ;
};

