#include "Game.h"

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
		Game::GameStart();
		break;
	case 2:
		Game::GameReadMe();
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
	Player player;
	Dealer dealer;
	DeckOfCards deck;

}

void Game::GameReadMe()
{
	cout << "Rules of the BlackJack Card Game" << endl;
}

void Game::GameScores()
{
	cout << "Game Scores" << endl;
}

void Game::GameEnd()
{
	cout << "Game End" << endl;
}
