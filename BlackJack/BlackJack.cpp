#include "Game.cpp"

int main()
{
	//srand(time(nullptr)); //makeing it unpredictable

	//DeckOfCards deckOfCards;

	//VectorOfStrAndIntPair DECK = deckOfCards.CreateADeckOfCards();

	//for (int i = 0; i < DECK.size(); i++)
	//{
	//	cout << DECK[i].first << " " << DECK[i].second << " ";
	//}

	//cout << endl;

	//DECK = deckOfCards.ShuffleTheDeck(DECK);

	//cout << endl;

	//for (int i = 0; i < DECK.size(); i++)
	//{
	//	cout << DECK[i].first << " " << DECK[i].second << " ";
	//}

	//cout << endl;
	
	//StrAndIntPair CardOfBack;

	//CardOfBack = deckOfCards.CardFromTheBackOfTheDeck(DECK);

	//cout << "\n" << CardOfBack.first << " " << CardOfBack.second << endl;

	//cout << endl;



	Game Game;
	Game.GameMenu();


	return 1;
}