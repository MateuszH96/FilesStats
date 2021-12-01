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
        throw "Failed open: " + fileName + "\n";
    }
    while (getline(file, lineFile))
    {
        numLine++;
    }
    file.close();
    return numLine;
}