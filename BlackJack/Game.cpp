#include "Game.h"

Player player;
Dealer dealer;
Deck deck;

void Game::Title() 
{
	cout << "--------------------------" << endl;
	cout << "|  BLACKJACK CARD GAME   |" << endl;
	cout << "|  ";
	Characters();
	cout << "   ";
	Characters();
	cout << "   |" << endl;
	cout << "--------------------------" << endl;
	Menu();
}

void Game::Characters()
{
	for (int i = 0; i < 2; i++)
	{
		cout << char(3) << char(4) << char(5) << char(6);
	}
}

void Game::Menu()
{
	string input{};
	cout << "--------------------------" << endl;
	cout << "| MENU                   |" << endl;
	cout << "| 1. START               |" << endl;
	cout << "| 2. HOW TO PLAY         |" << endl;
	cout << "| 3. QUIT                |" << endl;
	cout << "--------------------------" << endl;
	cout << "INPUT: ";
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
		cout << "WRONG INPUT!" << endl;
		system("pause");
		Menu();
		break;
	}
}

void Game::ReadMe()
{
	ifstream RulesOfBlackJack("rulesofblackjack.txt");
	if (RulesOfBlackJack.is_open())
		cout << RulesOfBlackJack.rdbuf();
	system("pause");
	Menu();
}

void Game::Name()
{
	string name;
	cout << "NAME: ";
	cin >> name;
	cin.clear();
	fflush(stdin);
	player.SetName(name);
	dealer.SetName("DEALER");
	player.SetMoney(3000);
	cout << "--------------------------" << endl;
	cout << "| YOUR NAME IS: " << *player.GetName() << endl;
	cout << "| YOUR BANK IS: " << *player.GetMoney() << endl;
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
		deck.ClearDeck();
		deck.SixDeck();
		deck.ShuffleDeck();
	}
}

void Game::Bet() 
{
	string bet{};
	cout << "BET: ";
	cin >> bet;
	if (atoi(bet.c_str()) > *player.GetMoney() || atoi(bet.c_str()) <= 0)
	{
		cout << "| TOO HIGH OR TOO LOW    |" << endl;
		cout << "| YOUR BANK IS: " << *player.GetMoney() << endl;
		cout << "BET: ";
		cin >> bet;
	}
	cin.clear();
	fflush(stdin);
	player.SetBet(atoi(bet.c_str()));
	cout << "--------------------------" << endl;
	cout << "| YOUR BET IS: " << *player.GetBet() << endl;
	cout << "--------------------------" << endl;
}

void Game::Deal()
{
	cout << "--------------------------" << endl;
	cout << "| DEAL:                  |" << endl;
	cout << "--------------------------" << endl;
	player.SetHand(deck.GetCard());
	dealer.SetHand(deck.GetCard());
	player.SetHand(deck.GetCard());
	dealer.SetHand(deck.GetCard());
	system("pause");
	if (player.BlackJack() && dealer.BlackJack())
	{
		PrintHands();
		cout << "--------------------------" << endl;
		cout << "| TWO BLACKJACKS!        |" << endl;
		cout << "| NO WINNER!             |" << endl;
		cout << "--------------------------" << endl;
		system("pause");
		Push();
	}
	if (player.BlackJack())
	{
		PrintHands();
		cout << "--------------------------" << endl;
		cout << "| " << *player.GetName() << " GOT A BLACKJACK!" << endl;
		cout << "--------------------------" << endl;
		system("pause");
		PlayerWin();
	}
	if (dealer.BlackJack())
	{
		PrintHands();
		cout << "--------------------------" << endl;
		cout << "| " << *dealer.GetName() << " GOT A BLACKJACK!" << endl;
		cout << "--------------------------" << endl;
		system("pause");
		Push();
	}
	Options();
}

void Game::PrintHands()
{
	cout << "--------------------------" << endl;
	cout << "| HANDS:                 |" << endl;
	cout << "--------------------------" << endl;
	cout << "| " << *player.GetName() << "'S HAND: ";
	player.PrintHand();
	cout << "| " << *dealer.GetName() << "'S HAND: ";
	dealer.PrintHand();
	cout << "--------------------------" << endl;
}

void Game::Options()
{
	string input{};
	player.SetHandValue(0);
	player.CountHandValue();
	while (player.GetHand().size() <= 5 && *player.GetHandValue() <= *GetTwentyOne())
	{
		PrintHands();
		cout << "--------------------------" << endl;
		cout << "| OPTIONS:               |" << endl;
		cout << "| 1. HIT                 |" << endl;
		cout << "| 2. STAND               |" << endl;
		cout << "| 3. DOUBLE DOWN         |" << endl;
		cout << "| 4. SURRENDER           |" << endl;
		cout << "--------------------------" << endl;
		cout << "INPUT: ";
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
			cout << "WRONG INPUT!" << endl;
			system("pause");
			Options();
			break;
		}
	}
	player.SetHandValue(0);
	Sequence();
}

void Game::Hit()
{
	cout << "--------------------------" << endl;
	cout << "| HIT:                   |" << endl;
	cout << "--------------------------" << endl;
	player.SetHand(deck.GetCard());
	Options();
}

void Game::Stand()
{
	cout << "--------------------------" << endl;
	cout << "| STAND:                 |" << endl;
	cout << "--------------------------" << endl;
	Sequence();
}

void Game::DoubleDown()
{
	cout << "--------------------------" << endl;
	cout << "| DOUBLE DOWN:           |" << endl;
	cout << "--------------------------" << endl;
	player.SetHand(deck.GetCard());
	// !!! BUG !!!
	player.SetBet(*player.GetBet() + *player.GetBet());
	Sequence();
}

void Game::Surrender()
{
	cout << "--------------------------" << endl;
	cout << "| SURRENDER:             |" << endl;
	cout << "--------------------------" << endl;
	player.SetBet(*player.GetBet() / 2);
	player.SetMoney(*player.GetMoney() + *player.GetBet());
	dealer.SetScore(*dealer.GetScore() + 1);
	Money();
	DeleteHands();
}

void Game::Sequence()
{
	DealerDecision();
	PrintHands();
	WinnerAndCounter();
	Money();
	DeleteHands();
}

void Game::DealerDecision()
{
	while (dealer.Decision() && dealer.GetHand().size() <= 5)
	{
		dealer.SetHand(deck.GetCard());
	}
}

void Game::WinnerAndCounter()
{
	cout << "--------------------------" << endl;
	cout << "| WINNER:                |" << endl;
	cout << "--------------------------" << endl;
	player.SetHandValue(0);
	player.CountHandValue();
	dealer.SetHandValue(0);
	dealer.CountHandValue();
	cout << "--------------------------" << endl;
	cout << "| PLAYER HAND VALUE: " << *player.GetHandValue() << endl;
	cout << "| DEALER HAND VALUE: " << *dealer.GetHandValue() << endl;
	cout << "--------------------------" << endl;
	if (*player.GetHandValue() > *GetTwentyOne())
	{
		DealerWin();
	}
	else if (*player.GetHandValue() == *dealer.GetHandValue())
	{
		Push();
	}
	else if (*dealer.GetHandValue() > *GetTwentyOne())
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
}

void Game::PlayerWin()
{
	player.SetScore(*player.GetScore() + 1);
	player.SetMoney(*player.GetMoney() + *player.GetBet());
	cout << "--------------------------" << endl;
	cout << "| " << *player.GetName() << " WIN" << endl;
	cout << "| " << *dealer.GetName() << " LOST" << endl;
	cout << "--------------------------" << endl;
	system("pause");
	Money();
	DeleteHands();
}

void Game::DealerWin()
{
	dealer.SetScore(*dealer.GetScore() + 1);
	player.SetMoney(*player.GetMoney() - *player.GetBet());
	cout << "--------------------------" << endl;
	cout << "| " << *dealer.GetName() << " WIN" << endl;
	cout << "| " << *player.GetName() << " LOST" << endl;
	cout << "--------------------------" << endl;
	system("pause");
	Money();
	DeleteHands();
}

void Game::Push()
{
	player.SetScore(*player.GetScore());
	dealer.SetScore(*dealer.GetScore());
	player.SetMoney(*player.GetMoney());
	cout << "--------------------------" << endl;
	cout << "| PUSH - NEITHER WINS     |" << endl;
	cout << "--------------------------" << endl;
	system("pause");
	Money();
	DeleteHands();
}

IntPtr Game::GetTwentyOne()
{
	return &TwentyOne;
}

void Game::Money() 
{
	if (*player.GetMoney() <= 0)
	{
		player.SetMoney(3000);
		dealer.SetScore(*dealer.GetScore() + 1);
		cout << "--------------------------" << endl;
		cout << "| YOUR BANK IS EMPTY!    |" << endl;
		cout << "| DEALER GOT A SCORE!    |" << endl;
		cout << "| YOUR NEW BANK IS: " << *player.GetMoney() << endl;
		cout << "--------------------------" << endl;
		system("pause");
	}
}

void Game::DeleteHands() 
{
	player.DeleteHand();
	dealer.DeleteHand();
	PrintScores();
	End();
}

void Game::PrintScores()
{
	cout << "--------------------------" << endl;
	cout << "| SCORES:                |" << endl;
	cout << "--------------------------" << endl;
	cout << "| " << *player.GetName() << "'S SCORE: " << *player.GetScore() << endl;
	cout << "| " << *dealer.GetName() << "'S SCORE: " << *dealer.GetScore() << endl;
	cout << "--------------------------" << endl;
	system("pause");
}

void Game::End()
{
	string input{};
	cout << "--------------------------" << endl;
	cout << "--------------------------" << endl;
	cout << "| END:                   |" << endl;
	cout << "| 1. NEW DEAL            |" << endl;
	cout << "| 2. MENU                |" << endl;
	cout << "--------------------------" << endl;
	cout << "INPUT: ";
	cin >> input;
	cin.clear();
	fflush(stdin);
	switch (atoi(input.c_str()))
	{
	case 1:
		cout << "--------------------------" << endl;
		cout << "| NEW DEAL:              |" << endl;
		cout << "--------------------------" << endl;
		Start();
		break;
	case 2:
		Menu();
		break;
	default:
		cout << "WRONG INPUT!" << endl;
		system("pause");
		End();
		break;
	}
}