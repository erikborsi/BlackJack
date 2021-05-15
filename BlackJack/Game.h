#pragma once
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

class Game
{
private:
	int TwentyOne = 21;
public:
	void Title();
	void Characters();
	void Menu();
	void ReadMe();
	void Name();
	void Start();
	void DeckAndShuffle();
	void Bet();
	void Deal();
	void PrintHands();
	void Options();
	void Hit();
	void Stand();
	void DoubleDown();
	void Surrender();

	void Split();
	void Insurance();

	void Sequence();
	void DealerDecision();
	void WinnerAndCounter();
	void PlayerWin();
	void DealerWin();
	void Push();
	IntPtr GetTwentyOne();
	void Money();
	void DeleteHands();
	void PrintScores();
	void End();
};