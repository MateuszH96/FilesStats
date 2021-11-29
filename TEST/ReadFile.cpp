#include "ReadFile.h"

ReadFile::ReadFile(std::string fileName)
{
    numLine = 0;
    this->fileName = fileName;
}

unsigned long int ReadFile::countLines()
{
    std::ifstream file(fileName);
    std::string lineFile;
    if (!file.is_open())
    {
        throw "Nie udało się otworzyć pliku: " + fileName + "\n";
    }
    while (getline(file, lineFile))
    {
        numLine++;
    }
    return numLine;
}