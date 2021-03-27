#include <iostream>
#include "CardLogic.h"

int main()
{
    /*Card myCard;

    myCard.SetSuit("HEARTS");
    myCard.SetValue(5);

    string something = myCard.GetSuit();

    myCard.PrintInfo();

    cout << something << endl;*/
    srand(time(NULL));

    InitializeSuitsArray();
    InitializeNumbersArray();

    InitializePairsFromTheArrays();
    cout << endl;

    InitializePairsFromTheArrays();
    cout << endl;

    InitializePairsFromTheArrays();
    cout << endl;
    
    
}

