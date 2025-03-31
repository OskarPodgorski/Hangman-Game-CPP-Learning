#include "Helper.h"
#include <windows.h>
#include <iostream>
#include <filesystem>

std::filesystem::path Helper::GetProgramPath()
{
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);

    return path;
}
