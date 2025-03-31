#include <string>
#include <cstring>

#pragma once
class Game
{
public:
	std::string originalWord;	
	unsigned char chances;

	Game(const std::string& word);
	~Game();

private:
	char* letters;

};

