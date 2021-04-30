#include "Dealer.h"

bool Dealer::Decision()
{
	Dealer::SetHandValue(0);
	Dealer::CountHandValue();
	if (HandValue <= 17)
	{
		return true;
	}
	else
	{
		return false;
	}
	Dealer::SetHandValue(0);
}
