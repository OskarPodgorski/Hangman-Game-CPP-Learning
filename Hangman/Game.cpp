#include "Game.h"

std::string originalWord;
unsigned char chances;
char* letters[];

Game::Game(const std::string& word)
{
	originalWord = word;
	chances = 0;
	letters = new char[originalWord.size()];

	std::strcpy(letters, originalWord.c_str());
}

Game::~Game()
{
	delete[] letters;
}