#include "Player.h"

string Player::GetPlayerName()
{
	return PlayerName;
}

void Player::SetPlayerName(string NameIn)
{
	PlayerName = NameIn;
}

int Player::GetPlayerHandValue()
{
	return PlayerHandValue;
}

void Player::SetPlayerHandsValue(int ValueIn)
{
	PlayerHandValue = ValueIn;
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
	cout << "Cards in Player Hand: " ;
	for (int i = 0; i < PlayerHand.size(); i++)
	{
		cout << PlayerHand[i].first << " " << PlayerHand[i].second << " ";
	}
	cout << endl;
}
