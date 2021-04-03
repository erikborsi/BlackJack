#include "Game.cpp"

int main()
{
	/*DeckOfCards deckOfCards;

	VectorOfStrAndIntPair DECK = deckOfCards.CreateADeckOfCards();

	for (int i = 0; i < DECK.size(); i++)
	{
		cout << DECK[i].first << " " << DECK[i].second << " ";
	}

	cout << endl;

	DECK = deckOfCards.ShuffleTheDeck(DECK);

	cout << endl;

	for (int i = 0; i < DECK.size(); i++)
	{
		cout << DECK[i].first << " " << DECK[i].second << " ";
	}

	cout << endl;
	*/


	Game Game;
	Game.GameMenu();


	return 1;
}