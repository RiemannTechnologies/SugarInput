#include <gtest/gtest.h>
#include "../lib/IOStreamReader.h"
TEST(basicIO, OKParse) {
    sugar::IOStreamReader reader(std::cin);
    int x;
    reader.TryRead(x);
    //ASSERT_EQ(x, 1);
}
