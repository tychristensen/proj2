//========================================================
//
//  File Name:   Bet.h
//
//  Author:  Mark Baldwin
//
//  Course and Assignment:   CSCI477 Project 2
//
//  Description:  Information about single bet
//  NOTE: No cpp file is needed since all methods are inline.
//
//=========================================================


#ifndef POKERPT1_BET_H
#define POKERPT1_BET_H


class Bet {
public:
    Bet() { m_amount = 0 ; m_player = 0  ;}
    Bet( int amount, int player ) { m_amount = amount ; m_player = player ; }

    int getAmount() { return m_amount ; }
    int getPlayer() { return m_player ; }

private:
    int m_amount ;   // amount of bet associated
    int m_player ; // player who made bet (0 or 1)
};


#endif //POKERPT1_BET_H
