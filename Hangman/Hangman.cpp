#include <iostream>
#include "Words.h"
#include "Helper.h"
#include "Game.h"
using namespace std;

int main()
{
    Words wordsDatabase(Words::GetWordsFilePath().string());
    Game game(wordsDatabase.GetRandomWord());

    cout << game.originalWord << endl;
}