#include "Player.h"

string Player::GetPlayerName()
{
	return PlayerName;
}

void Player::SetPlayerName(string NameIn)
{
	PlayerName = NameIn;
}

int Player::GetPlayerScore()
{
	return PlayerScore;
}

void Player::SetPlayerScore(int ScoreIn)
{
	PlayerScore = ScoreIn;
}

int Player::GetPlayerMoney()
{
	return PlayerMoney;
}

void Player::SetPlayerMoney(int MoneyIn)
{
	PlayerMoney = MoneyIn;
}

int Player::GetPlayerHandValue()
{
	return PlayerHandValue;
}

void Player::SetPlayerHandValue(int ValueIn)
{
	PlayerHandValue = ValueIn;
}

void Player::PrintPlayerHandValue()
{
	for (int i = 0; i < PlayerHand.size(); i++)
	{
		PlayerHandValue += PlayerHand[i].second;
	}
	cout << "Card value in Player hand: " << PlayerHandValue;
	cout << endl;
}

VectorOfStrAndIntPair Player::GetPlayerHand()
{
	return PlayerHand;
}

void Player::SetPlayerHand(VectorOfStrAndIntPair HandsIn)
{
	PlayerHand.reserve(PlayerHand.size() + HandsIn.size());
	PlayerHand.insert(PlayerHand.end(), HandsIn.begin(), HandsIn.end());
}

void Player::PrintPlayerHand()
{
	cout << "Cards in Player hand: " ;
	for (int i = 0; i < PlayerHand.size(); i++)
	{
		cout << PlayerHand[i].first << " " << PlayerHand[i].second << " ";
	}
	cout << endl;
}
