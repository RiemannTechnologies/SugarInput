#include "parser_test.h"

using namespace Sugar::Input;

TEST_F(ParserTest, char_test_ok)
{
  ASSERT_NO_THROW(Parser::Parse(char_test, "c"));
  ASSERT_EQ(char_test,'c');
}
TEST_F(ParserTest,char_test_not_a_valid_char_handling)
{
  ASSERT_THROW(Parser::Parse(char_test, "💀"), std::invalid_argument);//forbid unicode
  ASSERT_THROW(Parser::Parse(char_test,"な"),std::invalid_argument);
  ASSERT_THROW(Parser::Parse(char_test, "dog"), std::invalid_argument);
}
