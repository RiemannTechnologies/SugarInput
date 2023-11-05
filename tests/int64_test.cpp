//
// Created by thonk on 07.01.2023.
//
#include "parser_test.h"

using namespace Sugar::Input;
TEST_F(ParserTest, longlong_test_ok)
{
  ASSERT_NO_THROW(Parser::Parse(longlong_test, "69"));
  ASSERT_EQ(longlong_test,69);
}
TEST_F(ParserTest,longlong_test_not_a_number_handling)
{
  ASSERT_THROW(Parser::Parse(longlong_test, "6amogus9"), std::invalid_argument);
  ASSERT_THROW(Parser::Parse(longlong_test, "dog"), std::invalid_argument);
  ASSERT_THROW(Parser::Parse(longlong_test, "dog420"), std::invalid_argument);
  ASSERT_THROW(Parser::Parse(longlong_test, "d420og"), std::invalid_argument);
}

TEST_F(ParserTest,longlong_test_underflow)
{
  input ="-999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
  ASSERT_THROW(Parser::Parse(longlong_test, input),std::out_of_range);
  ASSERT_THROW(Parser::Parse(longlong_test,"-9223372036854775809"),std::out_of_range);
  ASSERT_NO_THROW(Parser::Parse(longlong_test,"-9223372036854775807"));
}

TEST_F(ParserTest,longlong_test_overflow)
{
  input="999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
  ASSERT_THROW(Parser::Parse(longlong_test, input),std::out_of_range);
  ASSERT_THROW(Parser::Parse(longlong_test,"9223372036854775808"),std::out_of_range);
  ASSERT_NO_THROW(Parser::Parse(longlong_test,"9223372036854775807"));
}
