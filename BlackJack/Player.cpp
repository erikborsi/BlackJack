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

VectorOfStrAndIntPair Player::GetHand()
{
	return Hand;
}

void Player::SetHand(VectorOfStrAndIntPair HandsIn)
{
	Hand.reserve(Hand.size() + HandsIn.size());
	Hand.insert(Hand.end(), HandsIn.begin(), HandsIn.end());
}

void Player::PrintHand()
{
	cout << "Cards in Player hand: ";
	for (int i = 0; i < Hand.size(); i++)
	{
		cout << Hand[i].first << " " << Hand[i].second << ", ";
	}
	cout << endl;
}

void Player::PrintHandValue()
{
	for (int i = 0; i < Hand.size(); i++)
	{
		HandValue += Hand[i].second;
	}
	cout << "Card value in Player hand: " << HandValue << endl;
}

void Player::DeleteHand()
{
	Hand.clear();
}
