#include "Game.h"

Game::Game(const std::string& word)
{
	originalWord = word;
	chances = 3;
	originalLetters = new char[originalWord.size()+1];

	strcpy_s(originalLetters, originalWord.size() + 1, originalWord.c_str());
}

bool Game::TryLetter(const char& letter)
{
	bool isCorrect = ContainsLetter(letter);

	if (!isCorrect)
		chances--;

	return isCorrect;
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

Game::~Game()
{
	delete[] originalLetters;
}