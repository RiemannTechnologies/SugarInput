#include <gtest/gtest.h>
#include "../lib/IOStreamReader.h"

using namespace Sugar::Input;
TEST(error_handling, skipping) {
    std::stringstream input("abc d");

    m_IOStreamReader reader(input);

    int x;
    reader.m_TryRead(x);
    reader.skip();
    ASSERT_EQ(reader.input->peek(), 'd');
}

TEST(error_handling, multiskip)
{
    std::stringstream input("abc def ghi");

    m_IOStreamReader reader(input);

    reader.skip();
    reader.skip();
    ASSERT_EQ(reader.input->peek(), 'g');
}
TEST(error_handling, resume_read)
{
    std::stringstream input("abc, def, 123");

    m_IOStreamReader reader(input);
    int x;
    reader.m_TryRead(x);
    reader.skip(2);
    reader.m_TryRead(x);
    ASSERT_EQ(x,123);
}
TEST(error_handling, discard)
{
    std::stringstream input("rjgrjadgudbgfgh udheriu geuhgeriugadfg hdghgheruigheriuhgerawghrwiughqet");
    m_IOStreamReader reader(input);

    reader.discard_line();
    ASSERT_EQ(reader.input->peek(), EOF);
}