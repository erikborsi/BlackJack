#include <string>
#include <iostream>

using namespace std;

class Card
{
	string suit;
	int number;
public:
	void SetSuit(string SuitIn);
	void SetNumber(int NumberIn);
	string GetSuit();
	int GetNumber();
	void PrintInfo();
};

void Card::SetSuit(string SuitIn)
{
	suit = SuitIn;
}

void Card::SetNumber(int NumberIn)
{
	number = NumberIn;
}

string Card::GetSuit()
{
	return suit;
}

int Card::GetNumber()
{
	return number;
}

void Card::PrintInfo()
{
	cout << suit << endl;
	cout << number << endl;
}