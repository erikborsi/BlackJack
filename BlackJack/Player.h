#pragma once
#include "MainHeader.h"

class Player
{
private:
	string PlayerName;
	int PlayerScore;
	VectorOfStrAndIntPair PlayerHands;
protected:
	inline string GetPlayerName();
	inline void SetPlayerName(string NameIn);
	inline int GetPlayerScore();
	inline void SetPlayerScore(int ScoreIn);
	inline VectorOfStrAndIntPair GetPlayerHands();
	inline void SetPlayerHands(VectorOfStrAndIntPair HandsIn);
};