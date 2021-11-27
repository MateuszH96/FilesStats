#include "ReadDictionary.h"

ReadDictionary::ReadDictionary(std::string path)
{
    this->path = path;
}

ReadDictionary::~ReadDictionary()
{
    delete[] dictionary;
    delete[] files;
    delete[] other;
}