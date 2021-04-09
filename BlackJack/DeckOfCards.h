#pragma once
#include "MainHeader.h"

class DeckOfCards
{
protected:
	inline StringPointer InitialiseSuitsArray();
	inline IntegerPointer InitialiseNumbersArray();
	inline VectorOfStrAndIntPair CreateADeckOfCards();
	inline VectorOfStrAndIntPair ShuffleTheDeck(VectorOfStrAndIntPair DeckForShuffling);
	//inline StrAndIntPair CardFromTheBackOfTheDeck(VectorOfStrAndIntPair DeckIn);
	//inline StrAndIntPair FromHandsToTheBackOfTheDeck(VectorOfStrAndIntPair DeckIn);
};