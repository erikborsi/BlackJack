#include <iostream>
#include <time.h>
#include "CardWithPairs.h"

int main()
{
	/*Card myCard;

	myCard.SetSuit("HEARTS");
	myCard.SetValue(5);

	string something = myCard.GetSuit();

	myCard.PrintInfo();

	cout << something << endl;*/
	
	srand((unsigned int)time(NULL));

	InitializeSuitsArray();
	InitializeNumbersArray();

	pair<string, int> card1 = InitializePairsFromTheArrays();
	cout << card1.first	<< endl;
	cout << card1.second << endl;
	cout << endl;

	pair<string, int> card2 = InitializePairsFromTheArrays();
	cout << card2.first << endl;
	cout << card1.second << endl;
	cout << endl;

	pair<string, int> card3 = InitializePairsFromTheArrays();
	cout << card3.first << endl;
	cout << card1.second << endl;
	cout << endl;

	pair<string, int> ArrayOfCards[3] = { card1, card2, card3 };

	cout << ArrayOfCards[0].first << endl;
	cout << endl;
	cout << ArrayOfCards[2].second << endl;

}

