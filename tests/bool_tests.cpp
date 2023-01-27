#include "parser_test.h"

using namespace Sugar::Input;
TEST_F(ParserTest, ParseBoolOk) {
  input = "true";

  Parser::Parse(bool_test, input);
  ASSERT_EQ(bool_test, true);

  input = "1";
  Parser::Parse(bool_test, input);
  ASSERT_EQ(bool_test, true);

  input = "false";
  bool_test = true;
  Parser::Parse(bool_test, input);
  ASSERT_EQ(bool_test, false);
}

TEST_F(ParserTest,ParseBoolInvalid)
{
	input = "2";
	ASSERT_THROW(Parser::Parse(bool_test,input),std::invalid_argument);
	input = "flase";
	ASSERT_THROW(Parser::Parse(bool_test,input),std::invalid_argument);
	input = "truee";
	ASSERT_THROW(Parser::Parse(bool_test,input),std::invalid_argument);
}