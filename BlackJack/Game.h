#pragma once
#include "MainHeader.h"
#include "Player.cpp"
#include "Dealer.cpp"
#include "DeckOfCards.cpp"

class Game : protected Player, protected Dealer, protected DeckOfCards
{
public:
	inline void GameMenu();
	inline void GameStart();
	inline void GameReadMe();
	inline void GameScores();
	inline void GameEnd();
};