#include "Helper.h"
#include <windows.h>
#include <iostream>
#include <filesystem>

std::string Helper::GetProgramPath()
{
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    std::string pathAsString(path);

    std::filesystem::path pathFileSystem = pathAsString;

    pathFileSystem = pathFileSystem.parent_path();
    pathFileSystem = pathFileSystem.append("words.txt");
    std::cout << pathFileSystem << std::endl;

    return pathFileSystem.string();
}
