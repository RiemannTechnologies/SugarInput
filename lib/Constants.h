#pragma once
#include <vector>
#define SUGAR_INPUT_OK 0
#define SUGAR_INPUT_UNKNOWN_ERROR 1
#define SUGAR_INPUT_USER_ERROR 2
#define SUGAR_INPUT_INVALID_CONTENT 4
#define SUGAR_INPUT_OUT_OF_RANGE 8
#define SUGAR_INPUT_NOSKIP 16

namespace Sugar::Input {
  typedef std::vector<std::string> raw_input;
}