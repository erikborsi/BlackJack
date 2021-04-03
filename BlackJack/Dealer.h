#pragma once
#include "MainHeader.h"

class Dealer
{
private:
	string DealerName;
	int DealerScore;
	VectorOfStrAndIntPair DealerHands;
protected:
	inline string GetDealerName();
	inline void SetDealerName(string NameIn);
	inline int GetDealerScore();
	inline void SetDealerScore(int ScoreIn);
	inline VectorOfStrAndIntPair GetDealerHands();
	inline void SetDealerHands(VectorOfStrAndIntPair HandsIn);
};