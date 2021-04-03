#include "Player.h"

string Player::GetPlayerName()
{
	cout << PlayerName << endl;
	return PlayerName;
}

void Player::SetPlayerName(string NameIn)
{
	PlayerName = NameIn;
}

int Player::GetPlayerScore()
{
	cout << PlayerScore << endl;
	return PlayerScore;
}

void Player::SetPlayerScore(int ScoreIn)
{
	PlayerScore = ScoreIn;
}

VectorOfStrAndIntPair Player::GetPlayerHands()
{
	return PlayerHands;
}

void Player::SetPlayerHands(VectorOfStrAndIntPair HandsIn)
{
	PlayerHands = HandsIn;
}
