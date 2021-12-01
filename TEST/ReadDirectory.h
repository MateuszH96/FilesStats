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
    std::string dirName;
    std::string *pathListFiles;
    void createArray();
    void getNumFiles();
    void countFilesStats();

  public:
    ReadDirectory(std::string path);
    ~ReadDirectory();
    unsigned int getFileNum();
    unsigned long long int getRowsNum();
    std::string getPath();
    friend std::ostream &operator<<(std::ostream &out, const ReadDirectory &rD);
};
std::string getNameFolder(std::string path);
std::ostream &operator<<(std::ostream &out, const ReadDirectory &rD);
#endif