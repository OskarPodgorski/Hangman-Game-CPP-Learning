#include "Helper.h"

std::filesystem::path Helper::GetProgramPath()
{
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);

    return path;
}

int Helper::GetRandomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);

    return dist(gen);
}
