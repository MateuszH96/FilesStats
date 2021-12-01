#ifndef READICTIONARY_H_
#define READICTIONARY_H_
#include "ReadFile.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
class ReadDirectory
{
  private:
    unsigned int fileNum;
    unsigned long long int rowsNum;
    unsigned int sizeStringArray;
    std::string path;
    std::string *pathListFiles;
    void createArray();
    void getNumFiles();
    void countFilesStats();

  public:
    ReadDirectory(std::string path);
    ~ReadDirectory();
    unsigned int getFileNum();
    unsigned long long int getRowsNum();
    friend std::string getNameFolder(ReadDirectory rD);
    friend std::ostream &operator<<(std::ostream &out, const ReadDirectory &rD);
};
std::ostream &operator<<(std::ostream &out, const ReadDirectory &rD);
std::string getNameFolder(ReadDirectory rD);
#endif