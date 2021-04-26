#pragma once
#include "MainHeader.h"

class Dealer
{
private:
	string Name{};
	int Score{}, HandValue{};
	VectorOfStrAndIntPair Hand;
public:
	string GetName();
	void SetName(string NameIn);
	int GetScore();
	void SetScore(int ScoreIn);
	int GetHandValue();
	void SetHandValue(int ValueIn);
	VectorOfStrAndIntPair GetHand();
	void SetHand(VectorOfStrAndIntPair HandsIn);
	void PrintHand();
	void CountAndPrintHandValue();
	void DeleteHand();
};