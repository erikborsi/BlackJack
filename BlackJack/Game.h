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
	void Deal(VectorOfStrAndIntPair DeckIn);
	int Bet();
	void Options(VectorOfStrAndIntPair DeckIn, int BetIn);
	void Hit(VectorOfStrAndIntPair DeckIn, int BetIn);
	void Stand(VectorOfStrAndIntPair DeckIn, int BetIn);
	void DoubleDown(VectorOfStrAndIntPair DeckIn, int BetIn);
	void Surrender(VectorOfStrAndIntPair DeckIn, int BetIn);
	void Decision(VectorOfStrAndIntPair DeckIn);
	void ValidatorAndCounter(VectorOfStrAndIntPair DeckIn, int BetIn);
	void End(VectorOfStrAndIntPair DeckIn);
};