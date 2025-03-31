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

	static std::filesystem::path GetWordsFilePath();
};