#include <string>
#include <cstring>
#include <iostream>

#pragma once
class Game
{
public:

	std::string originalWord;	
	unsigned char chances;

	Game(const std::string& word);
	~Game();

	bool TryLetter(const char& letter);

private:

	char* originalLetters;

	bool ContainsLetter(const char& letter);

};