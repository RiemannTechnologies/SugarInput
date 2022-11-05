#include <gtest/gtest.h>
#include "../lib/IOStreamReader.h"


TEST(string_tests, basic_read)
{
    std::stringstream input("abc");
    sugar::m_IOStreamReader reader(input);
    std::string x;
    reader.m_TryRead(x);
    ASSERT_EQ(x,"abc");
}
TEST(string_tests, quoted_read)
{
    std::stringstream input("\"abc\"");
    sugar::m_IOStreamReader reader(input);
    std::string x;
    reader.m_TryRead(x);
    ASSERT_EQ(x,"abc");
}
TEST(string_tests, quoted_read_with_spaces)
{
    std::stringstream input("\"abc def\"");
    sugar::m_IOStreamReader reader(input);
    std::string x;
    reader.m_TryRead(x);
    ASSERT_EQ(x,"abc def");
}
TEST(string_tests, quoted_read_with_spaces_and_quotes)
{
    std::stringstream input("\"abc def \\\"\"");
    sugar::m_IOStreamReader reader(input);
    std::string x;
    reader.m_TryRead(x);
    ASSERT_EQ(x,"abc def \"");
}
TEST(string_string, quoted_read_with_escape)
{
    std::stringstream input("\"abc def \\\" \"");
    sugar::m_IOStreamReader reader(input);
    std::string x;
    reader.m_TryRead(x);
    ASSERT_EQ(x,"abc def \" ");
}
TEST(string_tests, string_skip)
{
    std::stringstream input("abc def");
    sugar::m_IOStreamReader reader(input);
    std::string x;
    reader.skip();
    reader.m_TryRead(x);
    ASSERT_EQ(x,"def");
}
TEST(string_tests, quoted_string_skip)
{
    std::stringstream input("\"abc efg\" def");
    sugar::m_IOStreamReader reader(input);
    std::string x;
    reader.skip();
    reader.m_TryRead(x);
    ASSERT_EQ(x,"def");
}
