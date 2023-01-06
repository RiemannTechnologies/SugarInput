#include <gtest/gtest.h>
#include "../lib/IOStreamReader.h"

using namespace Sugar::Input;
TEST(integration, skip_invalid_input)
{
    std::stringstream input("abc 123");
    auto reader = IOStreamReader(input).skip_invalid_input(true);

    int x;
    reader.TryRead(x);
    ASSERT_EQ(x,123);
}
TEST(integration, skip_invalid_input_multi)
{
    std::stringstream input("abc def def 456");
    auto reader = IOStreamReader(input).skip_invalid_input(true);

    int x;
    reader.TryRead(x);
    ASSERT_EQ(x,456);
    
}