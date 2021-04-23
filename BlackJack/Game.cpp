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
	cout << "What is Your name?" << endl;
	cin >> input;
	player.SetName(input);
	dealer.SetName("Dealer");
	cout << "Hi " << player.GetName() << endl;
	cout << "Your game is loading now" << endl;
	for (int i = 0; i <= 10; i++)
	{
		cout << "=";
		chrono::microseconds dura(300000);
		this_thread::sleep_for(dura);
	}
	cout << " LOADED" << endl;
	game.Start();
}

void Game::Start()
{
	cout << player.GetName() << " your table is opened" << endl;
	player.SetMoney(3000);
	player.SetScore(0);
	cout << player.GetName() << " your bank is: " << player.GetMoney() << endl;
	cout << player.GetName() << " your score is: " << player.GetScore() << endl;
	chrono::seconds dura1(1);
	this_thread::sleep_for(dura1);
	cout << "The " << dealer.GetName() << " is opening a new deck of cards" << endl;
	for (int i = 0; i <= 10; i++)
	{
		cout << "=";
		chrono::microseconds dura2(300000);
		this_thread::sleep_for(dura2);
	}
	cout << " OPENED" << endl;
	VectorOfStrAndIntPair DECK = deck.CreateADeckOfCards();
	cout << "The " << dealer.GetName() << " is shuffling the deck" << endl;
	for (int i = 0; i <= 10; i++)
	{
		cout << "=";
		chrono::microseconds dura3(400000);
		this_thread::sleep_for(dura3);
	}
	cout << " SHUFFLED" << endl;
	DECK = deck.ShuffleTheDeck(DECK);
	game.Deal(DECK);
}

void Game::Deal(VectorOfStrAndIntPair DeckIn)
{
	int bet = game.Bet();
	int input{};
	cout << "Your bet is: " << bet << endl;
	cout << "Type number one to get a deal" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		player.SetHand(deck.GetCard(&DeckIn));
		dealer.SetHand(deck.GetCard(&DeckIn));
		game.Options(DeckIn, bet);
		break;
	default:
		cout << "Wrong input!" << endl;
		game.Deal(DeckIn);
		break;
	}
}

int Game::Bet() 
{
	int bet;
	cout << "Your bank has: " << player.GetMoney() << endl;
	cout << "To get a deal first you need to place your bet" << endl;
	cout << "Place your bet: " << endl;
	cin >> bet;
	if (bet > player.GetMoney())
	{
		cout << "The bet is too big" << endl;
		cout << "You got: " << player.GetMoney() << endl;
		cin >> bet;
		player.SetMoney(player.GetMoney() - bet);
		return bet;
	}
	else
	{
		player.SetMoney(player.GetMoney() - bet);
		return bet;
	}
}

void Game::Options(VectorOfStrAndIntPair DeckIn, int BetIn)
{
	int input{};
	cout << "---------------------------" << endl;
	player.PrintHand();
	dealer.PrintHand();
	player.PrintHandValue();
	dealer.PrintHandValue();
	cout << player.GetName() << " - your score is: " << player.GetScore() << endl;
	cout << "---------------------------" << endl;
	cout << "OPTIONS:" << endl;
	cout << "1. Hit" << endl;
	cout << "2. Stand" << endl;
	cout << "3. Double Down" << endl;
	cout << "4. Surrender" << endl;
	cout << "5. Menu" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		game.Hit(DeckIn, BetIn);
		break;
	case 2:
		game.Stand(DeckIn, BetIn);
		break;
	case 3:
		game.DoubleDown(DeckIn, BetIn);
		break;
	case 4:
		game.Surrender(DeckIn, BetIn);
		break;
	case 5:
		game.Menu();
	default:
		cout << "Wrong input!" << endl;
		game.Options(DeckIn, BetIn);
		break;
	}
}

void Game::Hit(VectorOfStrAndIntPair DeckIn, int BetIn)
{
	cout << player.GetName() << " - You hit with a new card" << endl;
	player.SetHand(deck.GetCard(&DeckIn));
	game.Decision(DeckIn);
	game.ValidatorAndCounter(DeckIn, BetIn);
	
}

void Game::Stand(VectorOfStrAndIntPair DeckIn, int BetIn)
{
	cout << player.GetName() << " - You stand with your card" << endl;
	game.Decision(DeckIn);
	game.ValidatorAndCounter(DeckIn, BetIn);
	game.Options(DeckIn, BetIn);
}

void Game::DoubleDown(VectorOfStrAndIntPair DeckIn, int BetIn)
{
	cout << player.GetName() << " - You doubled the bet" << endl;
	player.SetHand(deck.GetCard(&DeckIn));
	game.ValidatorAndCounter(DeckIn, BetIn);
	game.Options(DeckIn, BetIn);
}

void Game::Surrender(VectorOfStrAndIntPair DeckIn, int BetIn)
{
	cout << player.GetName() << " - You surrendered" << endl;
	cout << "The dealer wins" << endl;
	player.SetScore(player.GetScore() - 1);
	game.Deal(DeckIn);
}

void Game::Decision(VectorOfStrAndIntPair DeckIn)
{
	if (dealer.GetHandValue() < 18)
	{
		dealer.SetHand(deck.GetCard(&DeckIn));
	}
}

void Game::ValidatorAndCounter(VectorOfStrAndIntPair DeckIn, int BetIn)
{
	bool winner;
	winner = (player.GetHandValue() > 21) ? player.GetHandValue() : 21;
	if (winner == true)
	{
		cout << "You won " << endl;
		player.PrintHand();
		player.PrintHandValue();
		dealer.PrintHand();
		dealer.PrintHandValue();
		player.SetScore(player.GetScore() + 1);
		player.SetMoney(player.GetMoney() + BetIn);
	}
	else
	{
		player.PrintHand();
		player.PrintHandValue();
		dealer.PrintHand();
		dealer.PrintHandValue();
		cout << "Dealer won" << endl;
		player.SetScore(player.GetScore() - 1);
	}
	game.End(DeckIn);
}

void Game::End(VectorOfStrAndIntPair DeckIn)
{
	int input{};
	cout << "Do you want a new deal? " << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		game.Deal(DeckIn);
		player.DeleteHand();
		dealer.DeleteHand();
	case 2:
		game.Menu();
	default:
		cout << "Wrong input!" << endl;
		game.End(DeckIn);
		break;
	}

}
