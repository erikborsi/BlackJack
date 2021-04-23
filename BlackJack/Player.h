#pragma once
#include "MainHeader.h"

class Player
{
private:
	string Name;
	int Score;
	int Money;
	int HandValue;
	VectorOfStrAndIntPair Hand;
public:
	string GetName();
	void SetName(string NameIn);
	int GetScore();
	void SetScore(int ScoreIn);
	int GetMoney();
	void SetMoney(int MoneyIn);
	int GetHandValue();
	void SetHandValue(int ValueIn);
	void PrintHandValue();
	VectorOfStrAndIntPair GetHand();
	void SetHand(VectorOfStrAndIntPair HandsIn);
	void PrintHand();
	void DeleteHand();
};