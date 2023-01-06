//
// Created by thonk on 05.01.2023.
//

#include "PhoneNumber.h"
char Sugar::Input::PhoneNumber::m_TryRead(std::istream &_in) {
  char result = SUGAR_INPUT_OK;

  m_IOStreamReader reader(_in);

  result = reader.m_TryRead(value);

  std::regex filter(R"(^[+]{1}(?:[0-9\-\(\)\/\.]\s?){6, 15}[0-9]{1}$)");
  if(!std::regex_match(value,filter))
    result|=SUGAR_INPUT_INVALID_CONTENT;
  return result;
}
