#include <string>

using namespace std;

class Suit 
{
	string _suit;
protected:
	void setSuit(string suitIn);
	string getSuit();

};

void Suit::setSuit(string suitIn) 
{
	_suit = suitIn;
}

string Suit::getSuit() 
{
	return _suit;
}