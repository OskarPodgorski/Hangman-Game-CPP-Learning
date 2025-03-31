#include "Words.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "Helper.h"

vector<string> wordsVector;

	Words::Words(const string& wordsFilePath)
	{
		fstream file(wordsFilePath);

		std::string line;
		while (std::getline(file, line))
		{
			wordsVector.emplace_back(line);
		}
	}

	string Words::GetRandomWord()
	{
		if (wordsVector.empty()) 
		{
			return "";
		}

		return wordsVector[Helper::GetRandomInt(0, wordsVector.size() - 1)];
	}

	std::filesystem::path Words::GetWordsFilePath()
	{
		std::filesystem::path pathFS = Helper::GetProgramPath();

		pathFS = pathFS.parent_path();

		return pathFS.append("words.txt");
	}