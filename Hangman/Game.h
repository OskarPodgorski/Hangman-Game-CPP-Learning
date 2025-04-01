#include <string>
#include <cstring>
#include <iostream>
#include "Helper.h";

#pragma once
class Game
{
public:

	std::string originalWord;

	Game(const std::string& word);
	~Game();

	bool TryLetter(const char& letter);
	int GetChances() const;

private:

	char* originalLetters;
	char* modifiedLetters;
	unsigned char chances;

	bool ContainsLetter(const char& letter);
	char* MakeBlankSpaces(const std::string& word);
};