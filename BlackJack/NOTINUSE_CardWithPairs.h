#include <string>
#include <iostream>

using namespace std;

string* InitializeSuitsArray()
{
	static string SuitsArray[4] = { "HEARTS", "CLUBS", "DIAMONDS", "SPADES" };
	return SuitsArray;
}

int* InitializeNumbersArray()
{
	static int NumbersArray[10] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	return NumbersArray;
}

int RandomSuit()
{
	int randomSuit = rand() % 4;
	return randomSuit;
}

int RandomNumber()
{
	int randomNumber = rand() % 10;
	return randomNumber;
}

pair<string, int> InitializePairsFromTheArrays()
{
	int randomSuit = RandomSuit();
	int randomNumber = RandomNumber();
	string* suitsPointer = InitializeSuitsArray();
	int* numbersPointer = InitializeNumbersArray();
	pair<string, int> CARD;
	CARD.first = suitsPointer[randomSuit];
	CARD.second = numbersPointer[randomNumber];
	return CARD;
}