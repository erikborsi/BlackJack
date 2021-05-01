#include "Deck.h"

StrPtr Deck::SuitsArray()
{
	static string SuitsArray[4] = { "CLUBS", "HEARTS", "SPADES", "DIAMONDS" };
	return SuitsArray;
}

StrPtr Deck::RankArray()
{
	static string RankArray[13] = { "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING" };
	return RankArray;
}

VecOfStrAndStrPair Deck::CreateDeck()
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

void Deck::SixDeck()
{
	for (int i = 0; i <= 5; i++)
	{
		CreateDeck();
	}
}

VecOfStrAndStrPair Deck::ShuffleDeck()
{
	random_shuffle(Deck.begin(), Deck.end());
	return Deck;
}

VecOfStrAndStrPair Deck::GetCard()
{
	VecOfStrAndStrPair TemporaryVector;
	StrAndStrPair TemporaryCard;
	TemporaryCard = Deck.back();
	TemporaryVector.push_back(TemporaryCard);
	Deck.pop_back();
	return TemporaryVector;
}

VecOfStrAndStrPair Deck::GetDeck()
{
	return Deck;
}

void Deck::ClearDeck()
{	
	Deck.clear();
}
