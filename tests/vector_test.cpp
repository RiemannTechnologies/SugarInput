#include <gtest/gtest.h>

#include "../lib/Datatypes/Vector.h"
#include "../lib/IOStreamReader.h"

using namespace Sugar::Input;
TEST(vector_test, test_basic_input)
{
  Vector<int> vector;

  std::stringstream input("12 23 123 33");
  auto reader = IOStreamReader(input);

  reader.TryRead(vector);

  std::vector<int> expected_output = {12, 23, 123, 33};
  ASSERT_EQ(vector.data, expected_output);
}

TEST(vector_test, skip_test)
{
  Vector<int> vector;

  std::stringstream input("12 23 6amogus9 33\n 12 13");
  auto reader = IOStreamReader(input).skip_invalid_input(true);

  reader.TryRead(vector);

  std::vector<int> expected_output = {12, 13};
  ASSERT_EQ(vector.data, expected_output);
}