#include "Game.h"

Player player;
Dealer dealer;
DeckOfCards deck;

void Game::Title() 
{
	cout << "BlackJack Card Game" << endl;
	Menu();
}

void Game::Menu()
{
	int input;
	cout << "Menu" << endl;
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
	string input;
	cout << "Name:" << endl;
	cin >> input;
	player.SetName(input);
	dealer.SetName("Dealer");
	Start();
}

void Game::Start()
{
	deck.CreateADeckOfCards();
	deck.ShuffleTheDeck();
	Bet();
	Deal();
}

void Game::Bet() 
{
	int input;
	cout << "Bet:" << endl;
	cin >> input;
	player.SetBet(input);
}

void Game::Deal()
{
	cout << "Deal:" << endl;
	player.SetHand(deck.GetCard());
	player.SetHand(deck.GetCard());
	dealer.SetHand(deck.GetCard());
	dealer.SetHand(deck.GetCard());
	Print();
	Options();
}

void Game::Print()
{
	cout << "Hands:" << endl;
	player.PrintHand();
	player.PrintHandValue();
	dealer.PrintHand();
	dealer.PrintHandValue();
}

void Game::Options()
{
	int input{};
	cout << "Options: " << endl;
	cout << "1. Hit" << endl;
	cout << "2. Stand" << endl;
	cout << "3. Double Down" << endl;
	cout << "4. Surrender" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		Hit();
		break;
	case 2:
		Stand();
		break;
	case 3:
		DoubleDown();
		break;
	case 4:
		Surrender();
		break;
	default:
		cout << "Wrong input!" << endl;
		Options();
		break;
	}
}

void Game::Hit()
{
	cout << "Hit:" << endl;
	DealerDecision();
	Print();
	Winner();
	Counter();
	End();
}

void Game::Stand()
{
	cout << "Stand:" << endl;
	DealerDecision();
	Print();
	Winner();
	Counter();
	End();
}

void Game::DoubleDown()
{
	cout << "Double Down:" << endl;
	DealerDecision();
	Print();
	Winner();
	Counter();
	End();
}

void Game::Surrender()
{
	cout << "Surrender" << endl;
	DealerDecision();
	Print();
	Winner();
	Counter();
	End();
}

void Game::DealerDecision()
{

}

void Game::Winner()
{
	cout << "Winner:" << endl;

}

void Game::Counter() 
{
	cout << "Counter:" << endl;
}

void Game::End()
{
	int input{};
	cout << "End:" << endl;
	cout << "1. New Deal" << endl;
	cout << "2. Menu" << endl;
	switch (input)
	{
	case 1:
		Start();
		break;
	case 2:
		Menu();
		break;
	default:
		cout << "Wrong input!" << endl;
		End();
		break;
	}
}
