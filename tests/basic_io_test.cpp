#include <gtest/gtest.h>
#include "../lib/IOStreamReader.h"
using namespace Sugar::Input;


//Make sure the Reader::Read function works
TEST(ReaderTest, basic_input)
{
    std::istringstream input("1 2 3");
    std::vector<std::string> output;
    ASSERT_NO_THROW(output = Reader::Read(&input));
    ASSERT_EQ(output.size(),3);
    ASSERT_EQ(output[0],"1");
    ASSERT_EQ(output[1],"2");
    ASSERT_EQ(output[2],"3");
}

//make sure it works with empty input
TEST(ReaderTest, empty_input)
{
    std::istringstream input("");
    std::vector<std::string> output;
    ASSERT_NO_THROW(output = Reader::Read(&input));
    ASSERT_EQ(output.size(),0);
}
