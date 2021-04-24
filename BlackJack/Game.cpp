#include "Game.h"

Player player;
Dealer dealer;
DeckOfCards deck;

void Game::Menu()
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
		Setup();
		break;
	case 2:
		ReadMe();
		break;
	case 3:
		exit(1);
		break;
	default:
		cout << "Wrong input!" << endl;
		Menu();
		break;
	}
}

void Game::ReadMe()
{
	int input;
	ifstream RulesOfBlackJack("rulesofblackjack.txt");

	if (RulesOfBlackJack.is_open())
		cout << RulesOfBlackJack.rdbuf();

	cout << endl;
	cout << "Game Menu" << endl;
	cout << "Choose from the options:" << endl;
	cout << "1. Start game" << endl;
	cout << "2. Quit game" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		Setup();
		break;	
	case 2:
		exit(1);
		break;
	default:
		cout << "Wrong input!" << endl;
		Menu();
		break;
	}
}

void Game::Setup() 
{
	deck.CreateADeckOfCards();
	deck.ShuffleTheDeck();

	Deal();
}

void Game::Start()
{

}

void Game::Options()
{

}

void Game::Print()
{
	player.PrintHand();
	player.PrintHandValue();
	dealer.PrintHand();
	dealer.PrintHandValue();
}

void Game::Deal()
{
	player.SetHand(deck.GetCard());
	player.SetHand(deck.GetCard());
	dealer.SetHand(deck.GetCard());
	dealer.SetHand(deck.GetCard());
	Print();
}

void Game::Bet() 
{

}

void Game::Hit()
{

}

void Game::Stand()
{

}

void Game::DoubleDown()
{

}

void Game::Surrender()
{

}

void Game::Decision()
{

}

void Game::Validator()
{

}

void Game::Counter() 
{

}

void Game::End()
{

}
