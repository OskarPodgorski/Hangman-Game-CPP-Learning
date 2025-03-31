#include <iostream>
#include "Words.h"
#include "Helper.h"

using namespace std;

int main()
{
    Words wordsDatabase(Helper::GetProgramPath());   

    cout << wordsDatabase.wordsVector.size() << endl;
}