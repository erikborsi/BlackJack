#include "DeckOfCards.h"

StringPointer DeckOfCards::SuitsArray()
{
	static string SuitsArray[4] = { "CLUBS", "HEARTS", "SPADES", "DIAMONDS" };
	return SuitsArray;
}

StringPointer DeckOfCards::RankArray()
{
	static string RankArray[13] = { "ACE", "2", "3", "4", "5", "6", "7", "8", "9", "10", "JACK", "QUEEN", "KING" };
	return RankArray;
}

VectorOfStrAndStrPair DeckOfCards::CreateADeckOfCards()
{
	StringPointer suitPointer = SuitsArray();
	StringPointer rankPointer = RankArray();

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			suitPointer[j];
			Deck.push_back(StrAndStrPair(suitPointer[j], rankPointer[i]));
		}
		rankPointer[i];
	}
	return Deck;
}

VectorOfStrAndStrPair DeckOfCards::ShuffleTheDeck()
{
	random_shuffle(Deck.begin(), Deck.end());
	return Deck;
}

VectorOfStrAndStrPair DeckOfCards::GetCard()
{
	VectorOfStrAndStrPair TemporaryVector;
	StrAndStrPair TemporaryCard;
	TemporaryCard = Deck.back();
	TemporaryVector.push_back(TemporaryCard);
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

