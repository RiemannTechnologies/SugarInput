#include <gtest/gtest.h>

#include "Datatypes/Vector.h"
#include "IOStreamReader.h"
#include "Parser.h"
using namespace Sugar::Input;


//read 3 numbers, test if they are read correctly
TEST(vector_test, basic_input)
{
    std::string input = "1 2 3";
    std::istringstream stream(input);
    Vector<int> input_vector;
    auto raw_results = Reader::Read(&stream);
    ASSERT_EQ(raw_results, std::vector<std::string>({"1","2","3"}));
    Parser::Parse(input_vector,raw_results);
    ASSERT_EQ(input_vector.data[0], 1);
    ASSERT_EQ(input_vector.data[1], 2);
    ASSERT_EQ(input_vector.data[2], 3);
}

TEST(vector_test, malformed_input)
{
    std::string input = "1 amogus 3";
    std::istringstream stream(input);
    Vector<int> input_vector;
    auto raw_results = Reader::Read(&stream);
    ASSERT_EQ(raw_results, std::vector<std::string>({"1","amogus","3"}));
    ASSERT_THROW(Parser::Parse(input_vector,raw_results),std::invalid_argument);
}