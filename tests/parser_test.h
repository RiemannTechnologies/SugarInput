#pragma once

#include <gtest/gtest.h>
#include <string>
#include <Constants.h>
#include <Parser.h>
class ParserTest : public ::testing::Test {
 protected:
  std::string string_test;
  float float_test = 0;
  double double_test = 0.0;
  std::int32_t int_test = 0;
  std::uint32_t uint_test = 0;
  std::int64_t longlong_test = 0;
  std::uint64_t ulonglong_test = 0;
  std::string input;
  char char_test = 0;
  void SetUp() override{
    string_test = "";
    float_test = 0;
    double_test = 0.0;
    int_test = 0;
    uint_test = 0;
    longlong_test = 0;
    ulonglong_test = 0;
    char_test = 0;
    input = "";
  }
};
