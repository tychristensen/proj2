//========================================================
//
//  File Name:   Player.h
//
//  Author:  Mark Baldwin
//
//  Course and Assignment:   CSCI477 Project 2 
//
//  Description:  Declaration of the Player class
//
//=========================================================

#pragma once

#include "Hand.h"
#include "BetHistory.h"

#include "constants.h"


//===================================================================
//
//  Class: Player
//
//  Contains the data describing a player in the game 
//
//===================================================================
class Player
{
public:
	Player(int id, int chips );

	void addChips( int chips ) { m_chips += chips; }
	int getChips() { return m_chips ; }
	int getId() { return m_id ; }
	Hand getHand() { return m_hand ; }
	void clearHand() { m_hand.clear() ;}
	void dealCard( Card c ) { m_hand.addCard(c) ;}

	virtual int getBet(Hand opponent, BetHistory bh, int bet2player, bool canraise, int pot) = 0 ;

protected:
	int m_id ; // identifier of player
	Hand m_hand ;  // the hand the player has
	int m_chips ;  // number of chips player owns

};

