
#include "ReadDirectory.h"
#include <filesystem>
#include <iostream>

int main(int argc, char *argv[])
{
    std::string path;
    if (argc > 1)
    {
        path = argv[1];
    }
    else
    {
        path = std::filesystem::current_path();
    }
    try
    {
        ReadDirectory rD(path);
        std::cout << rD;
    }
    catch (const char *message)
    {
        std::cout << message << '\n';
    }

    return 0;
}