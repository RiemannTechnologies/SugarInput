#include <gtest/gtest.h>
#include "../lib/IOStreamReader.h"
TEST(basicIOInt, OKParse) {
    std::stringstream input("12");

    sugar::IOStreamReader reader().
            for_input(input);
    reader = reader.skipInvalidInput(false);
    int x;
    reader.TryRead(x);

    ASSERT_EQ(x, 12);
}

TEST(basicIOInt, InvalidContentParse) {
    std::stringstream input("amogus");

    sugar::m_IOStreamReader reader(input);
    int x;

    char res = reader.m_TryRead(x);
    ASSERT_EQ(res, SUGAR_INPUT_INVALID_CONTENT);
}
TEST(basicIOInt, UnderflowContentParse)
{
    std::stringstream input("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
    sugar::m_IOStreamReader reader(input);
    int x;

    char res = reader.m_TryRead(x);

    ASSERT_EQ(res,SUGAR_INPUT_OUT_OF_RANGE);
}

