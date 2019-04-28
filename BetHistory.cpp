//========================================================
//
//  File Name:   BetHistory.cpp
//
//  Author:  Mark Baldwin
//
//  Course and Assignment:   CSCI477 Project 2 
//
//  Description:  BetHistory class
//
//=========================================================

#include "BetHistory.h"


//------------------------------------------------------------------------
// Name:  BetHistory::BetHistory()
//
// Description: Class Constructor
//
// Arguments: None
//
// Modifies:  Sets up the object
// 
// Returns: none
//
//--------------------------------------------------------------------
BetHistory::BetHistory(void)
{
    clearHistory() ;
}


//------------------------------------------------------------------------
// Name:  BetHistory::clearHistory()
//
// Description: Clears out the history
//
// Arguments: none
//
// Modifies: history information
// 
// Returns: none
//
//--------------------------------------------------------------------
void BetHistory::clearHistory()    // clears a hand
{
	m_count = 0 ;
} 

//------------------------------------------------------------------------
// Name:  Hand::addBet()
//
// Description: Add's a card to the hand.
//
// Arguments: 
//	Bet - bet to be added
//
// Modifies:
//   The bet information
// 
// Returns: none
//
//--------------------------------------------------------------------
void BetHistory::addBet(Bet bet)
{
	m_bets[m_count] = bet ;
	m_count++ ;
}


//------------------------------------------------------------------------
// Name:  BetHistory::getCount()
//
// Description: Gets the number of bets in the history
//
// Arguments: 
//
// Modifies: none
// 
// Returns: number of bets in hand
//
//--------------------------------------------------------------------
int BetHistory::getCount()
{
	return m_count ;
}  // end getCount

//------------------------------------------------------------------------
// Name:  Hand::getBet()
//
// Description: Get's a bet from the history
//
// Arguments: 
//	int - which bet to get
//
// Modifies: none
// 
// Returns: bet
//
//--------------------------------------------------------------------
Bet BetHistory::getBet(int n)    // Get a card from the hand
{
	return m_bets[n] ;
} 

