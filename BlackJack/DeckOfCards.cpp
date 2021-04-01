#include "DeckOfCards.h"

StringPointer DeckOfCards::InitialiseSuitsArray()
{
	static string SuitsArray[4] = { "HEARTS", "CLUBS", "DIAMONDS", "SPADES" };
	return SuitsArray;
}

IntegerPointer DeckOfCards::InitialiseNumbersArray()
{
	static int NumbersArray[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 11 };
	return NumbersArray;
}

VectorOfStrAndIntPair DeckOfCards::CreateADeckOfCards()
{
	StringPointer suitPointer = InitialiseSuitsArray();
	IntegerPointer numberPointer = InitialiseNumbersArray();
	vector<pair<string, int>> DeckOfCards;

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			suitPointer[j];
			DeckOfCards.push_back(StrAndIntPair(suitPointer[j], numberPointer[i]));
		}
		numberPointer[i];
	}

	for (int i = 0; i < 13; i++)
	{
		for (int j = 1; j < 2; j++)
		{
			suitPointer[j];
			DeckOfCards.push_back(StrAndIntPair(suitPointer[j], numberPointer[i]));
		}
		numberPointer[i];
	}

	for (int i = 0; i < 13; i++)
	{
		for (int j = 2; j < 3; j++)
		{
			suitPointer[j];
			DeckOfCards.push_back(StrAndIntPair(suitPointer[j], numberPointer[i]));
		}
		numberPointer[i];
	}

	for (int i = 0; i < 13; i++)
	{
		for (int j = 3; j < 4; j++)
		{
			suitPointer[j];
			DeckOfCards.push_back(StrAndIntPair(suitPointer[j], numberPointer[i]));
		}
		numberPointer[i];
	}

	return DeckOfCards;
}