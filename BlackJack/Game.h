#pragma once
#include "MainHeader.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

class Game
{
private:
	int TwentyOne = 21;
public:
	void Title();
	void Menu();
	void ReadMe();
	void Name();
	void CreateDeckAndShuffle();
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
	void WinnerAndCounter();
	int GetTwentyOne();
	void Money();
	void DeleteHands();
	void End();
};