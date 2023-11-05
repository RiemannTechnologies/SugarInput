#include <gtest/gtest.h>
#include "IOStreamReader.h"
#include "parser_test.h"
using namespace Sugar::Input;


TEST_F(ParserTest, string_parse_ok)
{
    input = "abcde123";
    ASSERT_NO_THROW(Parser::Parse(string_test,input));
    ASSERT_EQ(string_test,input);
}

TEST_F(ParserTest, string_parse_invalid)
{
    input = "🤤🙃🙃😕";
    ASSERT_THROW(Parser::Parse(string_test,input),std::invalid_argument);
}