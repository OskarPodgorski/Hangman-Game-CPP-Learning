#include "Game.h"

std::string originalWord;
unsigned char chances;
char* originalLetters;

Game::Game(const std::string& word)
{
	originalWord = word;
	chances = 3;
	originalLetters = new char[originalWord.size()+1];

	std::strcpy(originalLetters, originalWord.c_str());
}

Game::~Game()
{
	delete[] originalLetters;
}

bool Game::TryLetter(const char& letter)
{
	return ContainsLetter(letter);
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