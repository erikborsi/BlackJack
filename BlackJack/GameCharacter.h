#pragma once
#include "MainHeader.h"

class GameCharacter 
{
protected:
	string Name{};
	int Score{}, HandValue{};
	VecOfStrAndStrPair Hand{};
public:
	StrPtr GetName();
	void SetName(string NameIn);
	IntPtr GetScore();
	void SetScore(int ScoreIn);
	IntPtr GetHandValue();
	void SetHandValue(int ValueIn);
	VecOfStrAndStrPair GetHand();
	void SetHand(VecOfStrAndStrPair HandsIn);
	void PrintHand();
	void CountHandValue();
	void DeleteHand();
};