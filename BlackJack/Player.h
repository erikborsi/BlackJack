#pragma once
#include "MainHeader.h"

class Player
{
private:
	string Name;
	int Score;
	int Money;
	int Bet;
	int HandValue;
	VectorOfStrAndIntPair Hand;
public:
	string GetName();
	void SetName(string NameIn);
	int GetScore();
	void SetScore(int ScoreIn);
	int GetMoney();
	void SetMoney(int MoneyIn);
	int GetBet();
	void SetBet(int BetIn);
	int GetHandValue();
	void SetHandValue(int ValueIn);
	VectorOfStrAndIntPair GetHand();
	void SetHand(VectorOfStrAndIntPair HandsIn);
	void PrintHand();
	void PrintHandValue();
	void DeleteHand();
};