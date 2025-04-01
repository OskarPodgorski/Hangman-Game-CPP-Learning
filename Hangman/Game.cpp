#include "Game.h"

Game::Game(const std::string& word)
{
	originalWord = word;
	chances = 3;
	originalLetters = Helper::StringToCharArray(originalWord);
	modifiedLetters = Helper::StringToCharArray(originalWord);

	MakeBlankSpaces();
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

void Game::MakeBlankSpaces()
{
	int blankLetterIndex = Helper::GetRandomInt(0, originalWord.size() - 1);

	modifiedLetters[blankLetterIndex] = '_';
}

Game::~Game()
{
	delete[] originalLetters;
	delete[] modifiedLetters;
}