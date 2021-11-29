#include "ReadDirectory.h"
#include "ReadFile.h"
#include <gtest/gtest.h>
#define GTEST_COUT std::cerr << "[          ] [ INFO ]"
class mockReadFile : public ReadFile
{
};
TEST(ReadFileTest, countLinesInFile)
{
    int expected = 3;
    ReadFile a("words.txt");
    unsigned long long int actual = a.countLines();
    ASSERT_EQ(expected, actual);
    GTEST_COUT << "Expected: " << expected << " Actual: " << actual << '\n';
}
TEST(ReadDirectoryTest, countfiles)
{
    int expected = 2;
    std::string path = std::filesystem::current_path();
    ReadDirectory a(path + "/TEST");
    unsigned int actual = a.getFileNum();
    ASSERT_EQ(expected, actual);
    GTEST_COUT << "Expected: " << expected << " Actual: " << actual << '\n';
}
TEST(ReadDirectoryTest, countLines)
{
    int expected = 4;
    std::string path = std::filesystem::current_path();
    ReadDirectory a(path + "/TEST");
    unsigned int actual = a.getRowsNum();
    ASSERT_EQ(expected, actual);
    GTEST_COUT << "Expected: " << expected << " Actual: " << actual << '\n';
}
TEST(ReadDirectoryTest, checkPath)
{
    std::string path = std::filesystem::current_path();
    std::string expected = path + "/TEST";
    ReadDirectory a(path + "/TEST");
    std::string actual = a.getPath();
    ASSERT_EQ(expected, actual);
    GTEST_COUT << "Expected: " << expected << " Actual: " << actual << '\n';
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}