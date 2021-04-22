#pragma once
#include "MainHeader.h"

class Dealer
{
private:
	string DealerName;
	int DealerHandValue;
	VectorOfStrAndIntPair DealerHand;
public:
	string GetDealerName();
	void SetDealerName(string NameIn);
	int GetDealerHandValue();
	void SetDealerHandValue(int ValueIn);
	VectorOfStrAndIntPair GetDealerHand();
	void SetDealerHand(VectorOfStrAndIntPair HandsIn);
	void PrintDealerHand();
};