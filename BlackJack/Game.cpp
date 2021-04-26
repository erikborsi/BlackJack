#include "Game.h"

Player player;
Dealer dealer;
DeckOfCards deck;


void Game::Title() 
{
	cout << "--------------------------" << endl;
	cout << "|  BlackJack Card Game   |" << endl;
	cout << "--------------------------" << endl;
	Menu();
}

void Game::Menu()
{
	string input{};
	cout << "--------------------------" << endl;
	cout << "| Menu                   |" << endl;
	cout << "| 1. Start game          |" << endl;
	cout << "| 2. Read about the game |" << endl;
	cout << "| 3. Quit game           |" << endl;
	cout << "--------------------------" << endl;
	cout << "Input: ";
	cin >> input;
	cin.clear();
	fflush(stdin);
	switch (atoi(input.c_str()))
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
	ifstream RulesOfBlackJack("rulesofblackjack.txt");

	if (RulesOfBlackJack.is_open())
		cout << RulesOfBlackJack.rdbuf();
	Menu();
}

void Game::Setup() 
{
	string name;
	cout << "Name: ";
	cin >> name;
	cin.clear();
	fflush(stdin);
	player.SetName(name);
	dealer.SetName("Dealer");
	player.SetMoney(3000);
	cout << "--------------------------" << endl;
	cout << "| Your name is: " << player.GetName() << endl;
	cout << "| Your bank is: " << player.GetMoney() << endl;
	cout << "--------------------------" << endl;
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
	string bet{};
	cout << "Bet: ";
	cin >> bet;
	cin.clear();
	fflush(stdin);
	player.SetBet(atoi(bet.c_str()));
	player.SetMoney(player.GetMoney() - player.GetBet());
	cout << "--------------------------" << endl;
	cout << "| Your bet is: " << player.GetBet() << endl;
	cout << "| Your bank is: " << player.GetMoney() << endl;
	cout << "--------------------------" << endl;
}

void Game::Deal()
{
	string deal{};
	cout << "--------------------------" << endl;
	cout << "| Deal:                  |" << endl;
	cout << "--------------------------" << endl;
	system("pause");
	player.SetHand(deck.GetCard());
	player.SetHand(deck.GetCard());
	dealer.SetHand(deck.GetCard());
	dealer.SetHand(deck.GetCard());
	cin.clear();
	fflush(stdin);
	Print();
	Options();
}

void Game::Print()
{
	cout << "--------------------------" << endl;
	cout << "| Hands:                 |" << endl;
	cout << "--------------------------" << endl;
	player.PrintHand();
	dealer.PrintHand();
}

void Game::Options()
{
	string input{};
	cout << "--------------------------" << endl;
	cout << "| Options:               |" << endl;
	cout << "| 1. Hit                 |" << endl;
	cout << "| 2. Stand               |" << endl;
	cout << "| 3. Double Down         |" << endl;
	cout << "| 4. Surrender           |" << endl;
	cout << "--------------------------" << endl;
	cout << "Input: ";
	cin >> input;
	cin.clear();
	fflush(stdin);
	switch (atoi(input.c_str()))
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
	cout << "--------------------------" << endl;
	cout << "| Hit:                   |" << endl;
	cout << "--------------------------" << endl;
	player.SetHand(deck.GetCard());
	Sequence();
}

void Game::Stand()
{
	cout << "--------------------------" << endl;
	cout << "| Stand:                 |" << endl;
	cout << "--------------------------" << endl;
	Sequence();
}

void Game::DoubleDown()
{
	cout << "--------------------------" << endl;
	cout << "| Double Down:           |" << endl;
	cout << "--------------------------" << endl;
	player.SetHand(deck.GetCard());
	Sequence();
}

void Game::Surrender()
{
	cout << "--------------------------" << endl;
	cout << "| Surrender:             |" << endl;
	cout << "--------------------------" << endl;
	Sequence();
}

void Game::Sequence()
{
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
	cout << "--------------------------" << endl;
	cout << "| Winner:                |" << endl;
	cout << "--------------------------" << endl;
	player.CountAndPrintHandValue();
	dealer.CountAndPrintHandValue();
}

void Game::Counter() 
{
	cout << "--------------------------" << endl;
	cout << "| Counter:               |" << endl;
	cout << "--------------------------" << endl;
}

void Game::End()
{
	string input{};
	cout << "--------------------------" << endl;
	cout << "| End:                   |" << endl;
	cout << "| 1. New Deal            |" << endl;
	cout << "| 2. Menu                |" << endl;
	cout << "--------------------------" << endl;
	cout << "Input: ";
	cin >> input;
	cin.clear();
	fflush(stdin);
	switch (atoi(input.c_str()))
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
