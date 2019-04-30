//========================================================
//
//  File Name:   main.cpp
//
//  Author:  Mark Baldwin
//
//  Course and Assignment:   CSCI477 Project 2 
//
//  Description:  This code is the driver for the class project
//
//=========================================================

//----- Includes and Namesapce ----------

#include <string> 
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Game.h"

using namespace std;


//----------------------------------------------------------------------
//
// Name:  main()
//
// Description: Test driver for game
//
// Inputs:
//    none
//
// Outputs:
//    returns 0
//
// Assumptions:
//    none
//
//----------------------------------------------------------------------
int main()
{
	string cmd ;  // command string

	// loop through a command loop to run varios hardwired test
	while( true ) // basically, an infinite loop
	{
		// get the comand
		cout << "Command (HH (human vs human), HA (human vs alpha), AA (alpha vs alpha), AB (alpha vs beta), QUIT): " ;
		getline( cin, cmd ) ;

		// flush the cin buffer
		cin.clear() ;
		fflush(stdin);

		// human vs human
		if( cmd == "HH" ||
			cmd == "hh" )
		{
			Game g1 ;   // create the game
			int result1, result2 ;  // results of the game

			if(g1.playGame(HUMAN, HUMAN, result1, result2, true) == true )
			{
				cout << "Game aborted." << endl ;
			}
		}
		// human vs alpha
		else if( cmd == "HA" ||
			     cmd == "ha"  )
		{
			Game g1 ;   // create the game
			int result1, result2 ;  // results of the game

			if(g1.playGame(HUMAN, ALPHA, result1, result2, true) == true )
			{
				cout << "Game aborted." << endl ;
			}
		}
		// alpha vs alpha
		else if( cmd == "AA" ||
			     cmd == "aa"  )
		{
			Game g1 ;   // create the game
			int result1, result2 ;  // results of the game

			if(g1.playGame(ALPHA, ALPHA, result1, result2, true) == true )
			{
				// note, since AI's never quit, this should never happen but kept for consistency
				cout << "Game aborted." << endl ;
			}
		}

		// alpha vs beta
		else if( cmd == "AB" ||
		         cmd == "ab"  )
        {
		    Game g1;
		    int result1, result2;

		    g1.playGame(ALPHA,BETA, result1, result2, true);
        }

		//Test beta
        else if( cmd == "Test" ||
                 cmd == "test"  )
        {
            int aWins = 0;
            int bWins = 0;
            for(int i = 0; i < 1000; i++) {
                Game g1;
                int result1, result2;

                g1.playGame(ALPHA, BETA, result1, result2, false);
                if (result1 > result2) {
                    aWins++;
                } else {
                    bWins++;
                }
            }
            cout << "Alpha won " << aWins << " times" << endl;
            cout << "Beta won " << bWins << " times" << endl;
        }

		// quit the program
		else if( cmd == "quit" ||      
			     cmd == "QUIT" )
		{
			break ;  // exit the loop
		}
		// command not understood
		else
		{
			cout << "Command " << cmd << " not understood." << endl ;
		} // end else
	}  // end do

	return 0;
} // end main

