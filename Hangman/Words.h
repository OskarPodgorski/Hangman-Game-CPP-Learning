#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "Helper.h"
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