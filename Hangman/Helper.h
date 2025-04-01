#include <windows.h>
#include <iostream>
#include <filesystem>
#include <random>
#include <string>

#pragma once
class Helper
{
public:

    static std::filesystem::path GetProgramPath();

    static int GetRandomInt(int min, int max);

    static char* StringToCharArray(const std::string& str);
};

