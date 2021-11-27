
// #include "ReadFile.h"
// #include <filesystem>
// #include <iostream>
// #include <string>
// namespace fs = std::filesystem;

// void demo_status(const fs::path &p, fs::file_status s)
// {
//     switch (s.type())
//     {
//     case fs::file_type::none:
//         std::cout << " has `not-evaluated-yet` type";
//         break;
//     case fs::file_type::not_found:
//         std::cout << " does not exist";
//         break;
//     case fs::file_type::regular:
//         std::cout << " is a regular file";
//         break;
//     case fs::file_type::directory:
//         std::cout << " is a directory";
//         break;
//     case fs::file_type::symlink:
//         std::cout << " is a symlink";
//         break;
//     case fs::file_type::block:
//         std::cout << " is a block device";
//         break;
//     case fs::file_type::character:
//         std::cout << " is a character device";
//         break;
//     case fs::file_type::fifo:
//         std::cout << " is a named IPC pipe";
//         break;
//     case fs::file_type::socket:
//         std::cout << " is a named IPC socket";
//         break;
//     case fs::file_type::unknown:
//         std::cout << " has `unknown` type";
//         break;
//     default:
//         std::cout << " has `implementation-defined` type";
//         break;
//     }
//     std::cout << '\n';
// }
// std::size_t number_of_files_in_directory(std::filesystem::path path)
// {
//     using std::filesystem::directory_iterator;
//     return std::distance(directory_iterator(path), directory_iterator{});
// }
// int main()
// {

//     std::string path = "/home/mateusz/Desktop/";
//     int i = 0;
//     std::string *test = new std::string[number_of_files_in_directory(path)];
//     for (const auto &entry : std::filesystem::directory_iterator(path))
//     {
//         test[i] = entry.path();
//         i++;
//     }
//     for (size_t j = 0; j < i; j++)
//     {
//         // std::cout << test[j] << std::endl;
//         demo_status(test[j], fs::status(test[j]));
//     }

//     return 0;
// }

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
namespace fs = std::filesystem;

void demo_status(fs::file_status s)
{
    switch (s.type())
    {
    case fs::file_type::none:
        std::cout << " has `not-evaluated-yet` type";
        break;
    case fs::file_type::not_found:
        std::cout << " does not exist";
        break;
    case fs::file_type::regular:
        std::cout << " is a regular file";
        break;
    case fs::file_type::directory:
        std::cout << " is a directory";
        break;
    case fs::file_type::symlink:
        std::cout << " is a symlink";
        break;
    case fs::file_type::block:
        std::cout << " is a block device";
        break;
    case fs::file_type::character:
        std::cout << " is a character device";
        break;
    case fs::file_type::fifo:
        std::cout << " is a named IPC pipe";
        break;
    case fs::file_type::socket:
        std::cout << " is a named IPC socket";
        break;
    case fs::file_type::unknown:
        std::cout << " has `unknown` type";
        break;
    default:
        std::cout << " has `implementation-defined` type";
        break;
    }
    std::cout << '\n';
}
int main()
{
    std::string path = "/home/mateusz/Desktop/test";
    // std::ifstream file(path);
    fs::file_status a = fs::status(path);
    if (a.type() == fs::file_type::not_found)
    {
        std::cout << "Folder nie istnieje!\n";
        return 1;
    }

    demo_status(fs::status(path));

    // std::cout << "Czy puste: " << (std::filesystem::is_empty(path) ? "puste" : "nie puste") << std::endl;
    return 0;
}