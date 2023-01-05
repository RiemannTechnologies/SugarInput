//
// Created by thonk on 05.01.2023.
//

#include "Email.h"
char Sugar::Input::Email::m_TryRead(std::istream &_in) {
  char result = SUGAR_INPUT_OK;
  m_IOStreamReader reader(_in);
  result = reader.m_TryRead(value);

  std::regex match(R"((\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+)");

  if(!std::regex_match(value,match))
    result |= SUGAR_INPUT_INVALID_CONTENT;
  return result;
}
