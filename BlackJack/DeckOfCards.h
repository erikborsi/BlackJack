#pragma once
#include "MainHeader.h"

class DeckOfCards
{
private:
	VectorOfStrAndIntPair Deck;
	VectorOfStrAndIntPair UsedDeck;
	StringPointer SuitsArray();
	IntegerPointer NumbersArray();
public:
	VectorOfStrAndIntPair CreateADeckOfCards();
	VectorOfStrAndIntPair ShuffleTheDeck();
	VectorOfStrAndIntPair GetCard();
	void PrintDeck();
};