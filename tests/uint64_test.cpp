#include "parser_test.h"

using namespace Sugar::Input;

TEST_F(ParserTest, ulonglong_test_ok)
{
ASSERT_NO_THROW(Parser::Parse(ulonglong_test, "69"));
ASSERT_EQ(ulonglong_test,69);
}
TEST_F(ParserTest,ulonglong_test_not_a_number_handling)
{
ASSERT_THROW(Parser::Parse(ulonglong_test, "6amogus9"), std::invalid_argument);
ASSERT_THROW(Parser::Parse(ulonglong_test, "dog"), std::invalid_argument);
ASSERT_THROW(Parser::Parse(ulonglong_test, "dog420"), std::invalid_argument);
ASSERT_THROW(Parser::Parse(ulonglong_test, "d420og"), std::invalid_argument);
}

TEST_F(ParserTest,ulonglong_test_invalid_negative)
{
input ="-999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
ASSERT_THROW(Parser::Parse(ulonglong_test, input),std::invalid_argument);
ASSERT_NO_THROW(Parser::Parse(ulonglong_test,"0"));
}

TEST_F(ParserTest,ulonglong_test_overflow)
{
input="999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
ASSERT_THROW(Parser::Parse(ulonglong_test, input),std::out_of_range);
ASSERT_THROW(Parser::Parse(ulonglong_test,"18446744073709551616"),std::out_of_range);
ASSERT_NO_THROW(Parser::Parse(ulonglong_test,"18446744073709551615"));
}
