#include <gtest/gtest.h>
#include "../lib/IOStreamReader.h"
using namespace Sugar::Input;
TEST(basicIOInt, OKParse) {
    std::stringstream input("12");

    auto reader = IOStreamReader(input)
            .skip_invalid_input(true);
    int x;
    reader.TryRead(x);
    ASSERT_EQ(x, 12);
}

TEST(basicIOInt, InvalidContentParse) {
    std::stringstream input("amogus");

    m_IOStreamReader reader(input);
    int x;

    char res = reader.m_TryRead(x);
    ASSERT_EQ(res, SUGAR_INPUT_INVALID_CONTENT);
}
TEST(basicIOInt, UnderflowContentParse)
{
    std::stringstream input("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
    m_IOStreamReader reader(input);
    int x;

    char res = reader.m_TryRead(x);

    ASSERT_EQ(res,SUGAR_INPUT_OUT_OF_RANGE);
}

