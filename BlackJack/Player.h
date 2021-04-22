#pragma once
#include "MainHeader.h"

class Player
{
private:
	string PlayerName;
	int PlayerHandValue;
	VectorOfStrAndIntPair PlayerHand;
public:
	string GetPlayerName();
	void SetPlayerName(string NameIn);
	int GetPlayerHandValue();
	void SetPlayerHandsValue(int ValueIn);
	VectorOfStrAndIntPair GetPlayerHand();
	void SetPlayerHand(VectorOfStrAndIntPair HandsIn);
	void PrintPlayerHand();
};