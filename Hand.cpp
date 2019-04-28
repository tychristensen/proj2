//========================================================
//
//  File Name:   Hand.cpp
//
//  Author:  Mark Baldwin
//
//  Course and Assignment:   CSCI477 Project 2 
//
//  Description:  Hand class
//
//=========================================================

#include "Hand.h"


//------------------------------------------------------------------------
// Name:  Hand::Hand()
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
Hand::Hand(void)
{
	clear() ;
}


//------------------------------------------------------------------------
// Name:  Hand::clear()
//
// Description: Clears out the hand
//
// Arguments: none
//
// Modifies: hand information
// 
// Returns: none
//
//--------------------------------------------------------------------
void Hand::clear()    // clears a hand
{
	m_count = 0 ;
} 

//------------------------------------------------------------------------
// Name:  Hand::addCard()
//
// Description: Add's a card to the hand.
//
// Arguments: 
//	Card - card to be added
//
// Modifies:
//   The hand information
// 
// Returns: none
//
//--------------------------------------------------------------------
void Hand::addCard(Card card)  // adds a card to the hand
{
	m_cards[m_count] = card ;
	m_count++ ;
}


//------------------------------------------------------------------------
// Name:  Hand::getCount()
//
// Description: Gets the number of cards in the hand
//
// Arguments: 
//
// Modifies: none
// 
// Returns: number of cards in hand
//
//--------------------------------------------------------------------
int Hand::getCount()   // Get the number of cards in the hand
{
	return m_count ;
}  // end getCount

//------------------------------------------------------------------------
// Name:  Hand::getCard()
//
// Description: Get's a card from the hand
//
// Arguments: 
//	int - which card to get
//
// Modifies: none
// 
// Returns: card selected
//
//--------------------------------------------------------------------
Card Hand::getCard(int n)    // Get a card from the hand
{
	return m_cards[n] ;
} 

//------------------------------------------------------------------------
// Name:  Hand::getVisible()
//
// Description: Get's the visible part of a hand
//
// Arguments:  none 
//
// Modifies: none
// 
// Returns: visible hand
//
//--------------------------------------------------------------------
Hand Hand::getVisible()
{
	Hand vhand ;

	// copy over the visible cards
	for( int index = 0 ; index < m_count-1 ; index++ )
	{
		vhand.m_cards[index] = m_cards[index+1] ;
	}
	vhand.m_count = m_count-1 ;
	return vhand ;
} 

//------------------------------------------------------------------------
// Name:  Hand::evaluate
//
// Description: Calculate the value of a hand
//
// Arguments: none
//
// Modifies: none
// 
// Returns: value of hand
//
//--------------------------------------------------------------------
int Hand::evaluate()   // evaluate the hand
{
	int value = 0 ;
	
	// add up the card values
	for( int index = 0 ; index < m_count ; index++ )
	{
		value += m_cards[index].getValue() ;
	}

	return value ;

}  // end evaluate