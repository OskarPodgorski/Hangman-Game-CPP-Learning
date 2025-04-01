#include <string>
#include <cstring>
#include <iostream>

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
	unsigned char chances;

	bool ContainsLetter(const char& letter);

};