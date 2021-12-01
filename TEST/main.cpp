#include "ReadDirectory.h"
#include "ReadFile.h"
#include <gtest/gtest.h>

TEST(ReadFileTest, countLinesInFile)
{
    // given:
    int expected = 3;
    ReadFile a("words.txt");

    // when:
    unsigned long long int actual = a.countLines();

    // then:
    ASSERT_EQ(expected, actual);
}
TEST(ReadDirectoryTest, countfiles)
{
    // given:
    int expected = 2;
    std::string path = std::filesystem::current_path();
    ReadDirectory a(path + "TEST");
    // when:
    unsigned int actual = a.getFileNum();
    // then:
    ASSERT_EQ(expected, actual);
}
TEST(ReadDirectoryTest, countLines)
{
    // given
    int expected = 4;
    std::string path = std::filesystem::current_path();
    ReadDirectory a(path + "/TEST");
    // when:
    unsigned int actual = a.getRowsNum();
    // then:
    ASSERT_EQ(expected, actual);
}
TEST(ReadDirectoryTest, checkPath)
{
    // given:
    std::string path = std::filesystem::current_path();
    std::string expected = "/TEST";
    ReadDirectory a(path + "/TEST");
    // when:
    std::string actual = getNameFolder(a);
    // then:
    ASSERT_EQ(expected, actual);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}