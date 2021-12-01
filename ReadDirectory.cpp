#include "ReadDirectory.h"

ReadDirectory::ReadDirectory(std::string path)
{
    this->path = path;
    rowsNum = 0;
    fileNum = 0;
    sizeStringArray = 0;
    createArray();
    countFilesStats();
}
ReadDirectory::~ReadDirectory()
{
    delete[] pathListFiles;
}

void ReadDirectory::createArray()
{
    int i = 0;

    std::filesystem::file_status a = std::filesystem::status(path);
    if (a.type() == std::filesystem::file_type::not_found)
    {
        throw "This path doesn't exist";
    }
    getNumFiles();
    pathListFiles = new std::string[sizeStringArray];
    for (const auto &entry : std::filesystem::recursive_directory_iterator(path))
    {
        pathListFiles[i++] = entry.path();
    }
}
void ReadDirectory::getNumFiles()
{
    for (const auto &entry : std::filesystem::recursive_directory_iterator(path))
    {
        sizeStringArray++;
    }
}
void ReadDirectory::countFilesStats()
{
    unsigned int i = 0;
    for (i = 0; i < sizeStringArray; i++)
    {
        std::filesystem::file_status checkStatusFile = std::filesystem::status(pathListFiles[i]);
        if (checkStatusFile.type() == std::filesystem::file_type::regular)
        {
            fileNum++;
            ReadFile *tmpFile = new ReadFile((pathListFiles[i]));
            rowsNum += tmpFile->countLines();
            delete tmpFile;
        }
    }
}

std::ostream &operator<<(std::ostream &out, const ReadDirectory &rD)
{

    out << "Folder NAME: " << getNameFolder(rD) << '\n'
        << "Number of files: " << rD.fileNum << '\n'
        << "Numbers of lines: " << rD.rowsNum << '\n';
    return out;
}
unsigned int ReadDirectory::getFileNum()
{
    return fileNum;
}
unsigned long long int ReadDirectory::getRowsNum()
{
    return rowsNum;
}
std::string getNameFolder(ReadDirectory rD)
{
    int i = rD.path.length() - 1;
    while (rD.path[i--] != '/' || rD.path[i--] != 0)
        ;

    return rD.path.substr(i + 1);
}