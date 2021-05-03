#include "Player.h"

IntPtr Player::GetMoney()
{
	return &Money;
}

void Player::SetMoney(int MoneyIn)
{
	Money = MoneyIn;
}

IntPtr Player::GetBet()
{
	return &Bet;
}

void Player::SetBet(int BetIn)
{
	Bet = BetIn;
}