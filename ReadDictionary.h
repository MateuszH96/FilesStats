#ifndef READICTIONARY_H_
#define READICTIONARY_H_
#include <fstream>
#include <iostream>
#include <string>
class ReadDictionary
{
  private:
    std::string path;
    std::string *dictionary;
    std::string *files;
    std::string *other;

  public:
    ReadDictionary(std::string path);
    ~ReadDictionary();
};

#endif