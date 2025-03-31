#include "Words.h"

vector<string> wordsVector;

	Words::Words(const string& wordsFilePath)
	{
		fstream file(wordsFilePath);

		string line;
		while (getline(file, line))
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

	filesystem::path Words::GetWordsFilePath()
	{
		filesystem::path pathFS = Helper::GetProgramPath();

		pathFS = pathFS.parent_path();

		return pathFS.append("words.txt");
	}