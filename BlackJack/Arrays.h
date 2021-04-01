#include <string>

using namespace std;
typedef string* StringPointer;
typedef int* IntegerPointer;

StringPointer InitialiseSuitsArray()
{
	static string SuitsArray[4] = { "HEARTS", "CLUBS", "DIAMONDS", "SPADES" };
	return SuitsArray;
}

IntegerPointer InitialiseNumbersArray()
{
	static int NumbersArray[10] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	return NumbersArray;
}
