#include <gtest/gtest.h>

#include "parser_test.h"
using namespace Sugar::Input;


TEST_F(ParserTest, string_test_ok)
{
  input = "abcde";
  ASSERT_NO_THROW(Parser::Parse(string_test, input));
  ASSERT_EQ(input,string_test);
}




