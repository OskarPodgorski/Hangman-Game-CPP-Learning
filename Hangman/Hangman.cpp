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

	while (game.chances > 0)
	{
		cout << static_cast<int>(game.chances) << endl;
		cout << "Input letter: ";
		char letter;
		cin >> letter;

		bool isCorrect = game.TryLetter(letter);

		if (isCorrect)
			cout << "Good" << endl;
		else
		{
			cout << "Wrong" << endl;
		}
	}

	cout << "Game Over !" << endl;
}