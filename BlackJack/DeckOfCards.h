#pragma once
#include "MainHeader.h"

class DeckOfCards
{
private:
	VectorOfStrAndStrPair Deck;
	StringPointer SuitsArray();
	StringPointer RankArray();
public:
	VectorOfStrAndStrPair CreateADeckOfCards();
	VectorOfStrAndStrPair ShuffleTheDeck();
	VectorOfStrAndStrPair GetCard();
	void PrintDeck();
};