#include <string>
#include <cstring>
#include <iostream>
#include "Helper.h"
#include <unordered_set>

#pragma once
class Game
{
public:

	std::string originalWord;

	Game(const std::string& word);
	~Game();

	bool TryLetter(const char& letter);
	int GetChances() const;
	std::string GetWordProgress() const;

private:

	char* originalLetters;
	char* modifiedLetters;
	unsigned char chances;

	bool InsertBlankLetter(const char& letter);
	void MakeBlankSpaces(short numOfBlanks);
};