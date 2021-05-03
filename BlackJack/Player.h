#pragma once
#include "GameCharacter.h"

class Player : public GameCharacter
{
private:
	int Money{}, Bet{};
public:
	IntPtr GetMoney();
	void SetMoney(int MoneyIn);
	IntPtr GetBet();
	void SetBet(int BetIn);
};