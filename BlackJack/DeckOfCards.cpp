#include "DeckOfCards.h"

StringPointer DeckOfCards::InitialiseSuitsArray()
{
	static string SuitsArray[4] = { "CLUBS", "HEARTS", "SPADES", "DIAMONDS" };
	return SuitsArray;
}

IntegerPointer DeckOfCards::InitialiseNumbersArray()
{
	static int NumbersArray[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
	return NumbersArray;
}

VectorOfStrAndIntPair DeckOfCards::CreateADeckOfCards()
{
	StringPointer suitPointer = InitialiseSuitsArray();
	IntegerPointer numberPointer = InitialiseNumbersArray();
	VectorOfStrAndIntPair DeckOfCards;

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			suitPointer[j];
			DeckOfCards.push_back(StrAndIntPair(suitPointer[j], numberPointer[i]));
		}
		numberPointer[i];
	}

	return DeckOfCards;
}

VectorOfStrAndIntPair DeckOfCards::ShuffleTheDeck(VectorOfStrAndIntPair DeckForShufflingIn)
{
	random_shuffle(DeckForShufflingIn.begin(), DeckForShufflingIn.end());
	return DeckForShufflingIn;
}

VectorOfStrAndIntPair DeckOfCards::GetCard(VectorOfStrAndIntPairPointer DeckFromIn)
{
	VectorOfStrAndIntPair TemporaryVector;
	StrAndIntPair TemporaryCARD;
	TemporaryCARD = DeckFromIn->back();
	TemporaryVector.push_back(TemporaryCARD);
	DeckFromIn->pop_back();
	return TemporaryVector;
}
