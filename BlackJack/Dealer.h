#pragma once
#include "MainHeader.h"

class Dealer
{
private:
	string DealerName;
	int DealerScore;
	int DealerHandValue;
	VectorOfStrAndIntPair DealerHand;
public:
	string GetDealerName();
	void SetDealerName(string NameIn);
	int GetDealerScore();
	void SetDealerScore(int ScoreIn);
	int GetDealerHandValue();
	void SetDealerHandValue(int ValueIn);
	void PrintPlayerHandValue();
	VectorOfStrAndIntPair GetDealerHand();
	void SetDealerHand(VectorOfStrAndIntPair HandsIn);
	void PrintDealerHand();
};