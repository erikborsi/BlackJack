#include "GameCharacter.h"

StrPtr GameCharacter::GetName()
{
	return &Name;
}

void GameCharacter::SetName(string NameIn)
{
	Name = NameIn;
}

IntPtr GameCharacter::GetScore()
{
	return &Score;
}

void GameCharacter::SetScore(int ScoreIn)
{
	Score = ScoreIn;
}

IntPtr GameCharacter::GetHandValue()
{
	return &HandValue;
}

void GameCharacter::SetHandValue(int ValueIn)
{
	HandValue = ValueIn;
}

VecOfStrAndStrPair GameCharacter::GetHand()
{
	return Hand;
}

void GameCharacter::SetHand(VecOfStrAndStrPair HandsIn)
{
	Hand.reserve(Hand.size() + HandsIn.size());
	Hand.insert(Hand.end(), HandsIn.begin(), HandsIn.end());
}

void GameCharacter::PrintHand()
{
	for (unsigned int i = 0; i < Hand.size(); i++)
	{
		cout << Hand[i].first << " OF " << Hand[i].second << ", ";
	}
	cout << endl;
}

void GameCharacter::CountHandValue()
{

	// TODO - 21 BLACKJACK WHEN ACE AND KING OR ACE AND JACK OR ACE AND QUEEN OR ACE AND TEN

	int value{};
	for (unsigned int i = 0; i < Hand.size(); i++)
	{
		if (Hand[i].first == "ACE")
		{
			value = 1;
		}
		if (Hand[i].first == "TWO")
		{
			value = 2;
		}
		if (Hand[i].first == "THREE")
		{
			value = 3;
		}
		if (Hand[i].first == "FOUR")
		{
			value = 4;
		}
		if (Hand[i].first == "FIVE")
		{
			value = 5;
		}
		if (Hand[i].first == "SIX")
		{
			value = 6;
		}
		if (Hand[i].first == "SEVEN")
		{
			value = 7;
		}
		if (Hand[i].first == "EIGHT")
		{
			value = 8;
		}
		if (Hand[i].first == "NINE")
		{
			value = 9;
		}
		if (Hand[i].first == "TEN")
		{
			value = 10;
		}
		if (Hand[i].first == "JACK")
		{
			value = 10;
		}
		if (Hand[i].first == "QUEEN")
		{
			value = 10;
		}
		if (Hand[i].first == "KING")
		{
			value = 10;
		}
		HandValue += value;
	}
}

void GameCharacter::DeleteHand()
{
	Hand.clear();
}