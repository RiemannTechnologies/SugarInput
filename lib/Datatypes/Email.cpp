//
// Created by thonk on 05.01.2023.
//

#include "Email.h"

namespace Sugar::Input {
  void Email::Parse(raw_input _input) {
    if(_input.size() > 1)
      throw std::invalid_argument("Too many arguments for Email");

    std::regex match(R"((\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+)");
    if (!std::regex_match(_input[0], match))
      throw std::invalid_argument("Invalid Email");

    value = _input[0];
  }
};