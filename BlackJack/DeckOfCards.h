#pragma once
#include "MainHeader.h"

class DeckOfCards
{
private:
	VectorOfStrAndIntPair Deck;
	StringPointer SuitsArray();
	IntegerPointer NumbersArray();
public:
	VectorOfStrAndIntPair CreateADeckOfCards();
	VectorOfStrAndIntPair ShuffleTheDeck();
	VectorOfStrAndIntPair GetCard();
};