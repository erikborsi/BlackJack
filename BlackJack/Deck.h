#pragma once
#include "MainHeader.h"

class Deck
{
private:
	VecOfStrAndStrPair Deck;
	StrPtr SuitsArray();
	StrPtr RankArray();
	VecOfStrAndStrPair CreateDeck();
public:
	void SixDeck();
	VecOfStrAndStrPair ShuffleDeck();
	VecOfStrAndStrPair GetCard();
	VecOfStrAndStrPair GetDeck();
	void ClearDeck();
};