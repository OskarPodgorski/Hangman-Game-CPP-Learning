#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Words.h"
#include "Helper.h"
#include "Game.h"
using namespace std;

int main()
{
	Words wordsDatabase(Words::GetWordsFilePath().string());
	Game game(wordsDatabase.GetRandomWord());

	int chances = game.GetChances();
	ostringstream strInt;

	while (chances > 0)
	{
		cout << game.GetWordProgress() << endl;
		strInt << "You have " << chances << " chances left";
		cout << strInt.str() << endl;
		strInt = ostringstream();

		cout << "Input letter: ";
		char letter;
		cin >> letter;

		system("cls");

		bool isCorrect = game.TryLetter(letter);

		if (isCorrect)
		{
			cout << "Good" << endl;

			if (game.CheckWin())
			{
				cout << "You win !!!";
				break;
			}
		}
		else
		{
			cout << "Wrong" << endl;

			chances = game.GetChances();
		}
	}

	cout << "Game Over !" << endl;
}