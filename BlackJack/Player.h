#pragma once
#include "MainHeader.h"

class Player
{
private:
	string Name{};
	int Score{}, Money{}, Bet{}, HandValue{};
	VectorOfStrAndStrPair Hand{};
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
	VectorOfStrAndStrPair GetHand();
	void SetHand(VectorOfStrAndStrPair HandsIn);
	void PrintHand();
	void CountHandValue();
	void DeleteHand();
};