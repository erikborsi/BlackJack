#include "Dealer.h"

string Dealer::GetDealerName()
{
	return DealerName;
}

void Dealer::SetDealerName(string NameIn)
{
	DealerName = NameIn;
}

int Dealer::GetDealerHandValue()
{
	return DealerHandValue;
}

void Dealer::SetDealerHandValue(int ValueIn)
{
	DealerHandValue = ValueIn;
}

VectorOfStrAndIntPair Dealer::GetDealerHand()
{
	return DealerHand;
}

void Dealer::SetDealerHand(VectorOfStrAndIntPair HandsIn)
{
	DealerHand.reserve(DealerHand.size() + HandsIn.size());
	DealerHand.insert(DealerHand.end(), HandsIn.begin(), HandsIn.end());
}

void Dealer::PrintDealerHand()
{
	cout << "Cards in Dealer Hand: ";
	for (int i = 0; i < DealerHand.size(); i++)
	{
		cout << DealerHand[i].first << " " << DealerHand[i].second << " ";
	}
	cout << endl;
}
