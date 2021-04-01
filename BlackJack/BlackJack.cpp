#include "DeckOfCards.cpp"

int main() 
{
	DeckOfCards deckOfCards;

	VectorOfStrAndIntPair DECK = deckOfCards.CreateADeckOfCards();

	for (int i = 0; i < DECK.size(); i++)
	{
		cout << DECK[i].first << " " << DECK[i].second << endl;
	}

	cout << endl;

	random_shuffle(DECK.begin(), DECK.end());

	for (int i = 0; i < DECK.size(); i++)
	{
		cout << DECK[i].first << " " << DECK[i].second << endl;
	}


	return 0;
}