#pragma once
#include "MainHeader.h"
#include "Player.h"
#include "Dealer.h"
#include "DeckOfCards.h"

class Game
{
public:
	void Title();
	void Menu();
	void ReadMe();
	void Setup();
	void Start();
	void Bet();
	void Deal();
	void Print();
	void Options();
	void Hit();
	void Stand();
	void DoubleDown();
	void Surrender();
	void Sequence();
	void DealerDecision();
	void Winner();
	void Counter();
	void End();
};