#include "Game.h"

Game::Game(const std::string& word)
{
	originalWord = word;
	chances = 3;
	originalLetters = Helper::StringToCharArray(originalWord);
	modifiedLetters = Helper::StringToCharArray(originalWord);

	MakeBlankSpaces(3);
}

bool Game::TryLetter(const char& letter)
{
	bool isCorrect = InsertBlankLetter(letter);

	if (!isCorrect)
		chances--;

	return isCorrect;
}

int Game::GetChances() const { return static_cast<int>(chances); }

std::string Game::GetWordProgress() const
{
	return modifiedLetters;
}

//private

bool Game::InsertBlankLetter(const char& letter)
{
	bool isCorrect = false;
	size_t size = originalWord.size();

	for (size_t i = 0; i < size; i++)
	{
		char* modPtr = &modifiedLetters[i];

		if (originalLetters[i] == letter && *modPtr == '_')
		{
			*modPtr = letter;
			isCorrect = true;
		}
	}
	return isCorrect;
}

void Game::MakeBlankSpaces(short numOfBlanks)
{
	std::unordered_set<int> alreadyUsedIndexes;

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