#include <iostream>
#include "Words.h"

using namespace std;

int main()
{
    Words wordsDatabase("C:/words.txt");   

    cout << wordsDatabase.wordsVector.size() << endl;
}