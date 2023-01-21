#include "parser_test.h"

using namespace Sugar::Input;

TEST_F(ParserTest, uint_test_ok)
{
  ASSERT_NO_THROW(Parser::Parse(uint_test, "69"));
  ASSERT_EQ(uint_test,69);
}
TEST_F(ParserTest,uint_test_not_a_number_handling)
{
  ASSERT_THROW(Parser::Parse(uint_test, "6amogus9"), std::invalid_argument);
  ASSERT_THROW(Parser::Parse(uint_test, "dog"), std::invalid_argument);
  ASSERT_THROW(Parser::Parse(uint_test, "dog420"), std::invalid_argument);
  ASSERT_THROW(Parser::Parse(uint_test, "d420og"), std::invalid_argument);
}

TEST_F(ParserTest,uint_test_invalid_negative)
{
  input ="-999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
  ASSERT_THROW(Parser::Parse(uint_test, input),std::invalid_argument);
  ASSERT_NO_THROW(Parser::Parse(uint_test,"0"));
}

TEST_F(ParserTest,uint_test_overflow)
{
  input="999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
  ASSERT_THROW(Parser::Parse(uint_test, input),std::out_of_range);
  ASSERT_THROW(Parser::Parse(uint_test,"4294967296"),std::out_of_range);
  ASSERT_NO_THROW(Parser::Parse(uint_test,"4294967295"));
}
