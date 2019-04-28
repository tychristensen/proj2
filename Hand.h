//========================================================
//
//  File Name:   Hand.h
//
//  Author:  Mark Baldwin
//
//  Course and Assignment:   CSCI477 Project 2 
//
//  Description:  Declaration of the Hand class
//
//=========================================================

#pragma once

#include "Card.h"
#include "constants.h"

//===================================================================
//
//  Class: Hand
//
//  Contains the data describing a hand in the game 
//
//===================================================================

class Hand
{
public:
	Hand(void);

	void clear() ;   // clears a hand
	void addCard(Card card) ; // adds a card to the hand
	int getCount() ;  // Get the number of cards in the hand
	Card getCard(int n)  ;  // Get a card from the hand
	Hand getVisible() ; // gets the visible part of the hand
	int evaluate() ;  // evaluate the hand

private:
	Card m_cards[MAX_CARDS_IN_HAND] ;  // cards held in the hand
	int m_count ;  // number of cards currently in the hand
};

