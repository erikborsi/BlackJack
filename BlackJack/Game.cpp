#include "Game.h"

Player player;
Dealer dealer;
DeckOfCards deck;
Game game;

void Game::GameMenu()
{
	int input;
	cout << "BlackJack Card Game" << endl;
	cout << "Game Menu" << endl;
	cout << "Choose from the options:" << endl;
	cout << "1. Start game" << endl;
	cout << "2. Read about the game" << endl;
	cout << "3. Quit game" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		game.GameStart();
		break;
	case 2:
		game.GameReadMe();
		break;
	case 3:
		exit(1);
		break;
	default:
		cout << "ERROR" << endl;
		break;
	}
}

void Game::GameStart()
{
	cout << "Game Start" << endl;
	// INITIALISE THE OBJECTS, USER INPUT FOR USER NAME, SET THE DEALER NAME TO DEALER, 
	VectorOfStrAndIntPair DECK = deck.CreateADeckOfCards();

	DECK = deck.ShuffleTheDeck(DECK);

	for (int i = 0; i < DECK.size(); i++)
	{
		cout << DECK[i].first << " " << DECK[i].second << " ";
	}

	cout << endl;
	cout << endl;

	player.SetPlayerHand(deck.GetCard(&DECK));
	dealer.SetDealerHand(deck.GetCard(&DECK));
	player.SetPlayerHand(deck.GetCard(&DECK));
	dealer.SetDealerHand(deck.GetCard(&DECK));

	player.PrintPlayerHand();
	dealer.PrintDealerHand();
	
	cout << endl;
	cout << endl;

}

void Game::GameReadMe()
{
	ifstream RulesOfBlackJack("rulesofblackjack.txt");

	if (RulesOfBlackJack.is_open())
		cout << RulesOfBlackJack.rdbuf();
}

void Game::GameScores()
{
	cout << "Game Scores" << endl;
	// DISPLAY THE HAND OF THE PLAYER AND DEALER, ADD TOGETHER THE SECOND PART OF THE PAIRS IN THE VECTOR OF HANDS
}

void Game::GameEnd()
{
	cout << "Game End" << endl;
	// WINNER THEN DELETE OR EMPTY OR ERASE THE HAND VECTORS
}
