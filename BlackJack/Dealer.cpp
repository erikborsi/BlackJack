#include "Dealer.h"

string Dealer::GetDealerName()
{
	return DealerName;
}

void Dealer::SetDealerName(string NameIn)
{
	DealerName = NameIn;
}

int Dealer::GetDealerScore()
{
	return DealerScore;
}

void Dealer::SetDealerScore(int ScoreIn)
{
	DealerScore = ScoreIn;
}

VectorOfStrAndIntPair Dealer::GetDealerHands()
{
	return DealerHands;
}

void Dealer::SetDealerHands(VectorOfStrAndIntPair HandsIn)
{
	DealerHands = HandsIn;
}
