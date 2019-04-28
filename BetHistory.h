//========================================================
//
//  File Name:   BetHistory.h
//
//  Author:  Mark Baldwin
//
//  Course and Assignment:   CSCI477 Project 2 
//
//  Description:  Declaration of the BetHistory class
//
//=========================================================

#pragma once

#include "constants.h"
#include "Bet.h"

//===================================================================
//
//  Class: BetHistory
//
//  Contains the data describing a set of bets 
//
//===================================================================
class BetHistory
{
public:
	BetHistory(void);

	void clearHistory() ;  // clear the history
	void addBet(Bet bet) ; // add a bet to the history
	int getCount() ;  // get the count of bets
	Bet getBet(int n) ;

private:
	Bet m_bets[MAX_NUMBER_RAISES*2+2] ;  // history information
	int m_count ;  // count of history members

};

