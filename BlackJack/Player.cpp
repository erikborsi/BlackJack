#include "Player.h"

string Player::GetName()
{
	return Name;
}

void Player::SetName(string NameIn)
{
	Name = NameIn;
}

int Player::GetScore()
{
	return Score;
}

void Player::SetScore(int ScoreIn)
{
	Score = ScoreIn;
}

int Player::GetMoney()
{
	return Money;
}

void Player::SetMoney(int MoneyIn)
{
	Money = MoneyIn;
}

int Player::GetBet()
{
	return Bet;
}

void Player::SetBet(int BetIn)
{
	Bet = BetIn;
}

int Player::GetHandValue()
{
	return HandValue;
}

void Player::SetHandValue(int ValueIn)
{
	HandValue = ValueIn;
}

VectorOfStrAndStrPair Player::GetHand()
{
	return Hand;
}

void Player::SetHand(VectorOfStrAndStrPair HandsIn)
{
	Hand.reserve(Hand.size() + HandsIn.size());
	Hand.insert(Hand.end(), HandsIn.begin(), HandsIn.end());
}

void Player::PrintHand()
{
	cout << "| Cards in Player hand: ";
	for (unsigned int i = 0; i < Hand.size(); i++)
	{
		cout << Hand[i].first << " " << Hand[i].second << ", ";
	}
	cout << endl;
}

void Player::CountHandValue()
{
	int value{};
	for (unsigned int i = 0; i < Hand.size(); i++)
	{
		if (Hand[i].second == "ACE")
		{
			value = 1;
		}
		if (Hand[i].second == "2")
		{
			value = 2;
		}
		if (Hand[i].second == "3")
		{
			value = 3;
		}
		if (Hand[i].second == "4")
		{
			value = 4;
		}
		if (Hand[i].second == "5")
		{
			value = 5;
		}
		if (Hand[i].second == "6")
		{
			value = 6;
		}
		if (Hand[i].second == "7")
		{
			value = 7;
		}
		if (Hand[i].second == "8")
		{
			value = 8;
		}
		if (Hand[i].second == "9")
		{
			value = 9;
		}
		if (Hand[i].second == "10")
		{
			value = 10;
		}
		if (Hand[i].second == "JACK")
		{
			value = 10;
		}
		if (Hand[i].second == "QUEEN")
		{
			value = 10;
		}
		if (Hand[i].second == "KING")
		{
			value = 10;
		}
		HandValue += value;
	}
}

void Player::DeleteHand()
{
	Hand.clear();
}
