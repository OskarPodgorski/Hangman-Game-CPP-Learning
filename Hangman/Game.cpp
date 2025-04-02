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
	bool isCorrect = ContainsLetter(letter);

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

bool Game::ContainsLetter(const char& letter)
{
	size_t size = originalWord.size();

	for (size_t i = 0; i < size; i++)
	{
		if (originalLetters[i] == letter)
		{
			return true;
		}
	}
	return false;
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