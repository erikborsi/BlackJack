#include "Dealer.h"

void Dealer::Decision()
{
	// if hand has ACE then do count 
	// 
	// if handvalue is 18 then NOT ask for a card
	// if handvalue is below 18 then ask for a card

	Dealer::SetHandValue(0);
	Dealer::CountHandValue();
	if (HandValue )
	{

	}
	Dealer::SetHandValue(0);
}
