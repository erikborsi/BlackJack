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
	void Options();
	void Print();
	void Deal();
	void Bet();
	void Hit();
	void Stand();
	void DoubleDown();
	void Surrender();
	void Decision();
	void Validator();
	void Counter();
	void End();
};