#pragma once
#include "MainHeader.h"
#include "Player.h"
#include "Dealer.h"
#include "DeckOfCards.h"

class Game
{
public:
	void Menu();
	void ReadMe();
	void Setup();
	void Start();
	void Deal();
	void ScoresValidatorAndCounter();
	void End();
};