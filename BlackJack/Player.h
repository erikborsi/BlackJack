#pragma once
#include "MainHeader.h"
#include "GameCharacter.h"

class Player : public GameCharacter
{
private:
	int Money{}, Bet{};
public:
	int GetMoney();
	void SetMoney(int MoneyIn);
	int GetBet();
	void SetBet(int BetIn);
};