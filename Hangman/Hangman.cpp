#include <iostream>
#include "Words.h"
#include "Helper.h"

using namespace std;

int main()
{
    Words wordsDatabase(Words::GetWordsFilePath().string());

    cout << wordsDatabase.wordsVector.size() << endl;
}