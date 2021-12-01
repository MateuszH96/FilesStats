#ifndef READFILE_H_
#define READFILE_H_
#include <fstream>
#include <iostream>
#include <string>
class ReadFile
{
  protected:
    unsigned long int numLine;
    std::string fileName;

  public:
    ReadFile(std::string fileName);
    unsigned long int countLines();
};
#endif