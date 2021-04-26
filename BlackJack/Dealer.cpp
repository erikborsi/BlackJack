#include "Dealer.h"

string Dealer::GetName()
{
	return Name;
}

void Dealer::SetName(string NameIn)
{
	Name = NameIn;
}

int Dealer::GetScore()
{
	return Score;
}

void Dealer::SetScore(int ScoreIn)
{
	Score = ScoreIn;
}

int Dealer::GetHandValue()
{
	return HandValue;
}

void Dealer::SetHandValue(int ValueIn)
{
	HandValue = ValueIn;
}

VectorOfStrAndIntPair Dealer::GetHand()
{
	return Hand;
}

void Dealer::SetHand(VectorOfStrAndIntPair HandsIn)
{
	Hand.reserve(Hand.size() + HandsIn.size());
	Hand.insert(Hand.end(), HandsIn.begin(), HandsIn.end());
}

void Dealer::PrintHand()
{
	cout << "| Cards in Dealer Hand: ";
	for (unsigned int i = 0; i < Hand.size(); i++)
	{
		cout << Hand[i].first << " " << Hand[i].second << ", ";
	}
	cout << endl;
}

void Dealer::CountAndPrintHandValue()
{
	for (unsigned int i = 0; i < Hand.size(); i++)
	{
		HandValue += Hand[i].second;
	}
	cout << "| Card value in Dealer hand: " << HandValue << " |" << endl;
}

void Dealer::DeleteHand()
{
	Hand.clear();
}
