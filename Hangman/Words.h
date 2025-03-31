#include <iostream>
#include <vector>
#include <filesystem>
using namespace std;

#pragma once
class Words
{
public:
	vector<string> wordsVector;

	Words(const string& wordsFilePath);

	string GetRandomWord();

	static std::filesystem::path GetWordsFilePath();
};