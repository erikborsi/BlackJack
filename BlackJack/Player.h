#pragma once
#include "MainHeader.h"

class Player
{
private:
	string PlayerName;
	int PlayerScore;
	int PlayerMoney;
	int PlayerHandValue;
	VectorOfStrAndIntPair PlayerHand;
public:
	string GetPlayerName();
	void SetPlayerName(string NameIn);
	int GetPlayerScore();
	void SetPlayerScore(int ScoreIn);
	int GetPlayerMoney();
	void SetPlayerMoney(int MoneyIn);
	int GetPlayerHandValue();
	void SetPlayerHandValue(int ValueIn);
	void PrintPlayerHandValue();
	VectorOfStrAndIntPair GetPlayerHand();
	void SetPlayerHand(VectorOfStrAndIntPair HandsIn);
	void PrintPlayerHand();
};