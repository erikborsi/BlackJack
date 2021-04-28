#pragma once
#include "MainHeader.h"

class Deck
{
private:
	VecOfStrAndStrPair Deck;
	StrPtr SuitsArray();
	StrPtr RankArray();
public:
	VecOfStrAndStrPair CreateDeck();
	VecOfStrAndStrPair ShuffleDeck();
	VecOfStrAndStrPair GetCard();
	void PrintDeck();
};