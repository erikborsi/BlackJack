#include "Game.h"

Player player;
Dealer dealer;
Deck deck;

void Game::Title() 
{
	cout << "--------------------------" << endl;
	cout << "|  BlackJack Card Game   |" << endl;
	cout << "|  ";
	for (int i = 0; i < 2; i++)
	{
		cout << char(3) << char(4) << char(5) << char(6);
	}
	cout << "   ";
	for (int i = 0; i < 2; i++)
	{
		cout << char(3) << char(4) << char(5) << char(6);
	}
	cout << "   |" << endl;
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
		Name();
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

void Game::Name()
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
	cout << "| Your name is: " << *player.GetName() << endl;
	cout << "| Your bank is: " << player.GetMoney() << endl;
	cout << "--------------------------" << endl;
	Start();
}

void Game::Start()
{
	DeckAndShuffle();
	Bet();
	Deal();
}

void Game::DeckAndShuffle()
{
	while (deck.GetDeck().size() < 10)
	{
		deck.CreateDeck();
		deck.ShuffleDeck();
	}
}

void Game::Bet() 
{
	string bet{};
	cout << "Bet: ";
	cin >> bet;
	if (atoi(bet.c_str()) > player.GetMoney() || atoi(bet.c_str()) <= 0)
	{
		cout << "| Too high or too low    |" << endl;
		cout << "| Your bank is: " << player.GetMoney() << endl;
		cout << "Bet: ";
		cin >> bet;
	}
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
	cout << "--------------------------" << endl;
	cout << "| Deal:                  |" << endl;
	cout << "--------------------------" << endl;
	player.SetHand(deck.GetCard());
	dealer.SetHand(deck.GetCard());
	player.SetHand(deck.GetCard());
	dealer.SetHand(deck.GetCard());
	system("pause");
	Options();
}

void Game::Print()
{
	cout << "--------------------------" << endl;
	cout << "| Hands:                 |" << endl;
	cout << "--------------------------" << endl;
	cout << "| " << *player.GetName() << "'s hand: ";
	player.PrintHand();
	cout << "| " << *dealer.GetName() << "'s hand: ";
	dealer.PrintHand();
}

void Game::Options()
{
	string input{};
	while (player.GetHand().size() <= 5)
	{
		Print();
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
	Sequence();
}

void Game::Hit()
{
	cout << "--------------------------" << endl;
	cout << "| Hit:                   |" << endl;
	cout << "--------------------------" << endl;
	player.SetHand(deck.GetCard());
	Options();
	DeckAndShuffle();
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
	player.SetBet(player.GetBet() + player.GetBet());
	Sequence();
	DeckAndShuffle();
}

void Game::Surrender()
{
	cout << "--------------------------" << endl;
	cout << "| Surrender:             |" << endl;
	cout << "--------------------------" << endl;

	//TODO SURRENDER OPTION

	Sequence();
}

void Game::Sequence()
{
	DealerDecision();
	Print();
	WinnerAndCounter();
	DeleteHands();
}

void Game::DealerDecision()
{
	while (dealer.Decision())
	{
		dealer.SetHand(deck.GetCard());
	}
	DeckAndShuffle();
}

void Game::WinnerAndCounter()
{
	int value{};
	cout << "--------------------------" << endl;
	cout << "| Winner:                |" << endl;
	cout << "--------------------------" << endl;
	player.SetHandValue(0);
	player.CountHandValue();
	dealer.SetHandValue(0);
	dealer.CountHandValue();
	cout << "| Player hand value: " << *player.GetHandValue() << endl;
	cout << "| Dealer hand value: " << *dealer.GetHandValue() << endl;
	if (*player.GetHandValue() > GetTwentyOne())
	{
		DealerWin();
	}
	else if (*player.GetHandValue() == *dealer.GetHandValue())
	{
		Push();
	}
	else if (*dealer.GetHandValue() > GetTwentyOne())
	{
		PlayerWin();
	}
	else if (*dealer.GetHandValue() > *player.GetHandValue())
	{
		DealerWin();
	}
	else if (*dealer.GetHandValue() == *player.GetHandValue())
	{
		Push();
	}
	else if (*dealer.GetHandValue() < *player.GetHandValue())
	{
		PlayerWin();
	}
	system("pause");
	Money();
}

void Game::PlayerWin()
{
	player.SetScore(*player.GetScore() + 1);
	dealer.SetScore(*dealer.GetScore() - 1);
	player.SetMoney(player.GetMoney() + player.GetBet() + player.GetBet());
	cout << "--------------------------" << endl;
	cout << "| " << *player.GetName() << " win" << endl;
	cout << "| " << *dealer.GetName() << " lost" << endl;
	cout << "--------------------------" << endl;
}

void Game::DealerWin()
{
	player.SetScore(*player.GetScore() - 1);
	dealer.SetScore(*dealer.GetScore() + 1);
	cout << "--------------------------" << endl;
	cout << "| " << *dealer.GetName() << " win" << endl;
	cout << "| " << *player.GetName() << " lost" << endl;
	cout << "--------------------------" << endl;
}

void Game::Push()
{
	player.SetScore(*player.GetScore());
	dealer.SetScore(*dealer.GetScore());
	player.SetMoney(player.GetMoney() + player.GetBet());
	cout << "--------------------------" << endl;
	cout << "| PUSH - NEITHER WINS     |" << endl;
	cout << "--------------------------" << endl;
}

int Game::GetTwentyOne()
{
	return TwentyOne;
}

void Game::Money() 
{
	if (player.GetMoney() <= 0)
	{
		player.SetMoney(3000);
		player.SetScore(*player.GetScore() - 1);
		dealer.SetScore(*dealer.GetScore() + 1);
		cout << "--------------------------" << endl;
		cout << "| Your bank is empty!    |" << endl;
		cout << "| Dealer got one score!  |" << endl;
		cout << "| Your new bank is: " << player.GetMoney() << endl;
		cout << "--------------------------" << endl;
		system("pause");
	}
}

void Game::DeleteHands() 
{
	player.DeleteHand();
	dealer.DeleteHand();
	End();
}

void Game::End()
{
	string input{};
	cout << "--------------------------" << endl;
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
		cout << "--------------------------" << endl;
		cout << "--------------------------" << endl;
		cout << "| NEW DEAL:              |" << endl;
		cout << "--------------------------" << endl;
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
