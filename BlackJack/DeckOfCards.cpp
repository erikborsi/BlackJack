#include "DeckOfCards.h"

StrPtr DeckOfCards::SuitsArray()
{
	static string SuitsArray[4] = { "CLUBS", "HEARTS", "SPADES", "DIAMONDS" };
	return SuitsArray;
}

StrPtr DeckOfCards::RankArray()
{
	static string RankArray[13] = { "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING" };
	return RankArray;
}

VecOfStrAndStrPair DeckOfCards::CreateADeckOfCards()
{
	StrPtr suitPointer = SuitsArray();
	StrPtr rankPointer = RankArray();

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			suitPointer[j];
			Deck.push_back(StrAndStrPair(rankPointer[i],suitPointer[j]));
		}
		rankPointer[i];
	}
	return Deck;
}

VecOfStrAndStrPair DeckOfCards::ShuffleTheDeck()
{
	random_shuffle(Deck.begin(), Deck.end());
	return Deck;
}

VecOfStrAndStrPair DeckOfCards::GetCard()
{
	VecOfStrAndStrPair TemporaryVector;
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

