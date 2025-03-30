#include <iostream>
#include <vector>
using namespace std;

#pragma once
class Words
{
public:
	vector<string> wordsVector;

	Words(const string& wordsFilePath);
};