#include "Player.h"

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
