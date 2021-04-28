#pragma once
#include "MainHeader.h"

class Dealer
{
private:
	string Name{};
	int Score{}, HandValue{};
	VectorOfStrAndStrPair Hand{};
public:
	string GetName();
	void SetName(string NameIn);
	int GetScore();
	void SetScore(int ScoreIn);
	int GetHandValue();
	void SetHandValue(int ValueIn);
	VectorOfStrAndStrPair GetHand();
	void SetHand(VectorOfStrAndStrPair HandsIn);
	void PrintHand();
	void CountHandValue();
	void DeleteHand();
};