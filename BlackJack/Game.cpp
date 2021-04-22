#include "Game.h"

Player player;
Dealer dealer;
DeckOfCards deck;
Game game;

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
		game.Setup();
		break;
	case 2:
		game.ReadMe();
		break;
	case 3:
		exit(1);
		break;
	default:
		cout << "Wrong input!" << endl;
		game.Menu();
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
		game.Setup();
		break;	
	case 2:
		exit(1);
		break;
	default:
		cout << "Wrong input!" << endl;
		game.Menu();
		break;
	}
}

void Game::Setup() 
{
	string input;
	int i;
	cout << "What is Your name?" << endl;
	cin >> input;
	player.SetPlayerName(input);
	dealer.SetDealerName("Dealer");
	cout << "Hi " << player.GetPlayerName() << endl;
	cout << "Your game is loading now" << endl;
	for (i = 0; i <= 10; i++)
	{
		cout << "=";
		chrono::microseconds dura(400000);
		this_thread::sleep_for(dura);
	}
	cout << " LOADED" << endl;
	game.Start();
}

void Game::Start()
{
	cout << player.GetPlayerName() << " your table is loaded" << endl;
	player.SetPlayerMoney(3000);
	player.SetPlayerScore(0);
	cout << player.GetPlayerName() << " your bank is: " << player.GetPlayerMoney() << endl;
	cout << player.GetPlayerName() << " your score is: " << player.GetPlayerScore() << endl;
	chrono::seconds dura1(1);
	this_thread::sleep_for(dura1);
	cout << "The " << dealer.GetDealerName() << " is opening a new deck of cards" << endl;
	chrono::seconds dura4(4);
	this_thread::sleep_for(dura4);
	VectorOfStrAndIntPair DECK = deck.CreateADeckOfCards();
	cout << "The " << dealer.GetDealerName() << " shuffled the deck" << endl;
	DECK = deck.ShuffleTheDeck(DECK);
	game.Deal();
}

void Game::Deal() 
{
	int bet;
	cout << "Place your bet: " << endl;
	cin >> bet;
	


}


void Game::ScoresValidatorAndCounter()
{
	cout << "Game Scores" << endl;
	
}

void Game::End()
{
	cout << "Game End" << endl;
	
}
