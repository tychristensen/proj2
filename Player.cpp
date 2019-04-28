//========================================================
//
//  File Name:   Player.cpp
//
//  Author:  Mark Baldwin
//
//  Course and Assignment:   CSCI477 Project 2 
//
//  Description:  base class for player decision making
//
//=========================================================
#include "Player.h"
#include "Hand.h"
#include <iostream>

//------------------------------------------------------------------------
// Name:  Player::Player()
//
// Description: Class Constructor
//
// Arguments: 
//	n - player identifer
//
// Modifies:  Sets up the player
// 
// Returns: none
//
//--------------------------------------------------------------------
Player::Player( int id, int chips )
{
	m_id = id ;
	m_chips = chips ;
}



