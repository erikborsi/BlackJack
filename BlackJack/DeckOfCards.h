#pragma once
#include "MainHeader.h"

class DeckOfCards
{
public:
	StringPointer InitialiseSuitsArray();
	IntegerPointer InitialiseNumbersArray();
	VectorOfStrAndIntPair CreateADeckOfCards();
	VectorOfStrAndIntPair ShuffleTheDeck(VectorOfStrAndIntPair DeckForShuffling);
	VectorOfStrAndIntPair GetCard(VectorOfStrAndIntPairPointer DeckFromIn);
};