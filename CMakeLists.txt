cmake_minimum_required(VERSION 3.13)
project(PokerPt1)

set(CMAKE_CXX_STANDARD 14)

add_executable(PokerPt1 main.cpp BetHistory.cpp BetHistory.h Game.cpp Game.h Hand.cpp Hand.h Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h AlphaPlayer.cpp AlphaPlayer.h BetaPlayer.cpp BetaPlayer.h Bet.h Card.h)