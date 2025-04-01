#include "Words.h"

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
		
		size_t wordsCount = wordsVector.size();
		return wordsVector[Helper::GetRandomInt(0, wordsCount > 0 ? wordsCount - 1 : 0)];
	}

	filesystem::path Words::GetWordsFilePath()
	{
		filesystem::path pathFS = Helper::GetProgramPath();

		pathFS = pathFS.parent_path();

		return pathFS.append("words.txt");
	}