#include "ReadFile.h"

ReadFile::ReadFile()
{
    numLine = 0;
}
ReadFile::~ReadFile()
{
}

void ReadFile::setNameFile(std::string fileName)
{
    this->fileName = fileName;
    setName = true;
}
unsigned long int ReadFile::getNumLines()
{
    return numLine;
}

void ReadFile::countLines()
{
    std::ifstream file(fileName);
    std::string lineFile;
    if (file.is_open())
    {
        std::cout << "Udało się!\n";
    }
    while (getline(file, lineFile))
    {
        if (lineFile.length() != 0)
        {
            size_t i;
            for (i = 0; i < lineFile.length(); i++)
            {
                if (!std::isblank(lineFile[i]))
                {
                    numLine++;
                    break;
                }
            }
        }
    }
}