#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;
typedef string* StringPointer;
typedef int* IntegerPointer;
typedef pair<string, int> StrAndIntPair;
typedef vector<pair<string, int>> VectorOfStrAndIntPair;

class DeckOfCards
{
public:
	StringPointer InitialiseSuitsArray();
	IntegerPointer InitialiseNumbersArray();
	VectorOfStrAndIntPair CreateADeckOfCards();
};