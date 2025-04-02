#include "Game.h"

Game::Game(const std::string& word)
{
	originalWord = word;
	chances = 5;
	lettersRemained = 3;

	originalLetters = Helper::StringToCharArray(originalWord);
	modifiedLetters = Helper::StringToCharArray(originalWord);

	MakeBlankSpaces(lettersRemained);
}

bool Game::TryLetter(const char& letter)
{
	bool isCorrect = InsertLetterToBlank(letter);

	if (!isCorrect)
		chances--;

	return isCorrect;
}

int Game::GetChances() const { return static_cast<int>(chances); }

std::string Game::GetWordProgress() const { return modifiedLetters; }

bool Game::CheckWin() const
{
	if (lettersRemained <= 0)
		return true;

	return false;
}

//private

bool Game::InsertLetterToBlank(const char& letter)
{
	bool isCorrect = false;
	size_t size = originalWord.size();

	for (size_t i = 0; i < size; i++)
	{
		char* modPtr = &modifiedLetters[i];

		if (originalLetters[i] == letter && *modPtr == '_')
		{
			*modPtr = letter;

			lettersRemained--;
			isCorrect = true;
		}
	}
	return isCorrect;
}

void Game::MakeBlankSpaces(short numOfBlanks)
{
	std::unordered_set<int> alreadyUsedIndexes;

	if (numOfBlanks > originalWord.size())
		numOfBlanks = originalWord.size();

	for (short s = 0; s < numOfBlanks; s++)
	{
		int blankLetterIndex;

		do
			blankLetterIndex = Helper::GetRandomInt(0, originalWord.size() - 1);
		while (!alreadyUsedIndexes.insert(blankLetterIndex).second);

		modifiedLetters[blankLetterIndex] = '_';
	}
}

Game::~Game()
{
	delete[] originalLetters;
	delete[] modifiedLetters;
}