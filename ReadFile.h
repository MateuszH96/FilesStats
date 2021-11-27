#ifndef READFILE_H_
#define READFILE_H_
#include <fstream>
#include <iostream>
#include <string>
class ReadFile
{
  private:
    unsigned long int numLine;
    std::string fileName;
    bool setName = false;

  public:
    ReadFile();
    void countLines();
    void setNameFile(std::string fileName);
    unsigned long int getNumLines();
    ~ReadFile();
};
#endif