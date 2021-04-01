#include <string>

using namespace std;

class Card
{
private:
	string suit;
	int number;
public:
	void SetSuit(string SuitIn) { suit = SuitIn; };
	void SetNumber(int NumberIn) { number = NumberIn; };
	string GetSuit() { return suit; };
	int GetNumber() { return number; };
	void PrintInfo() { cout << suit << endl; cout << number << endl; };
};
