#include "Words.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


	vector<string> wordsVector;

	Words::Words(const string & wordsFilePath)
	{
		fstream file(wordsFilePath);

		std::string line;
		while (std::getline(file, line))
		{
			wordsVector.emplace_back(line);
		}
	}