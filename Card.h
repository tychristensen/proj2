//========================================================
//
//  File Name:   Card.h
//
//  Author:  Mark Baldwin
//
//  Course and Assignment:   CSCI477 Project 2
//
//  Description:  Information about a card
//  NOTE: No cpp file is needed since all methods are inline.
//
//=========================================================

#ifndef POKERPT1_CARD_H
#define POKERPT1_CARD_H

#include <string>
using namespace std ;

class Card {
public:
    //Card() {};

    void setCard( string name, int value ) { m_cardName = name ; m_cardValue = value ; m_isFaceUp = true ; }
    int getValue() { return m_cardValue ; }
    string getName() { return m_cardName ; }
    bool isFaceUp() { return m_isFaceUp ; }
    void setFaceUp( bool faceup ) { m_isFaceUp = faceup ; }

private:
    string m_cardName ;  // the name of the card
    int m_cardValue ;	// the value associated with the card
    bool m_isFaceUp ;   // flag to indicate the card is faceup (i.e. seeable by all players)
};


#endif //POKERPT1_CARD_H
