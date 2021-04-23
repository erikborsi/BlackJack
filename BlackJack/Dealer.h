#pragma once
#include "MainHeader.h"

class Dealer
{
private:
	string Name;
	int Score;
	int HandValue;
	VectorOfStrAndIntPair Hand;
public:
	string GetName();
	void SetName(string NameIn);
	int GetScore();
	void SetScore(int ScoreIn);
	int GetHandValue();
	void SetHandValue(int ValueIn);
	void PrintHandValue();
	VectorOfStrAndIntPair GetHand();
	void SetHand(VectorOfStrAndIntPair HandsIn);
	void PrintHand();
	void DeleteHand();
};