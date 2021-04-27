#include "DeckOfCards.h"

StringPointer DeckOfCards::SuitsArray()
{
	static string SuitsArray[4] = { "CLUBS", "HEARTS", "SPADES", "DIAMONDS" };
	return SuitsArray;
}

IntegerPointer DeckOfCards::NumbersArray()
{
	static int NumbersArray[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	return NumbersArray;
}

VectorOfStrAndIntPair DeckOfCards::CreateADeckOfCards()
{
	StringPointer suitPointer = SuitsArray();
	IntegerPointer numberPointer = NumbersArray();

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			suitPointer[j];
			Deck.push_back(StrAndIntPair(suitPointer[j], numberPointer[i]));
		}
		numberPointer[i];
	}
	return Deck;
}

VectorOfStrAndIntPair DeckOfCards::ShuffleTheDeck()
{
	random_shuffle(Deck.begin(), Deck.end());
	return Deck;
}

VectorOfStrAndIntPair DeckOfCards::GetCard()
{
	VectorOfStrAndIntPair TemporaryVector;
	StrAndIntPair TemporaryCARD;
	TemporaryCARD = Deck.back();
	TemporaryVector.push_back(TemporaryCARD);
	Deck.pop_back();
	return TemporaryVector;
}

void DeckOfCards::PrintDeck()
{
	for (unsigned int i = 0; i < Deck.size(); i++)
	{
		cout << Deck[i].first << " " << Deck[i].second << ", ";
	}
	cout << endl;
}

