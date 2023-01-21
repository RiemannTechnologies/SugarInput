//
// Created by thonk on 05.01.2023.
//

#include "PhoneNumber.h"
void Sugar::Input::PhoneNumber::Parse(Sugar::Input::raw_input _input) {
  if(_input.size()>1)
    throw std::invalid_argument("Too many arguments for PhoneNumber");
  auto t_value = _input[0];
  std::regex filter(R"(^[+]{1}(?:[0-9\-\(\)\/\.]\s?){6, 15}[0-9]{1}$)");
  if(!std::regex_match(t_value,filter))
    throw std::invalid_argument("Invalid content in PhoneNumber");
  value = t_value;

}
