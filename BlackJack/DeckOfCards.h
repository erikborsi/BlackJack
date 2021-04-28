#pragma once
#include "MainHeader.h"

class DeckOfCards
{
private:
	VecOfStrAndStrPair Deck;
	StrPtr SuitsArray();
	StrPtr RankArray();
public:
	VecOfStrAndStrPair CreateADeckOfCards();
	VecOfStrAndStrPair ShuffleTheDeck();
	VecOfStrAndStrPair GetCard();
	void PrintDeck();
};