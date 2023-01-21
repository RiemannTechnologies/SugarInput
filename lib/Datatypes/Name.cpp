#include "Name.h"


void Sugar::Input::Name::Parse(raw_input _input) {

  if(_input.size()>1)
    throw std::invalid_argument("Too many arguments for Name");
  auto t_value = _input[0];
  for(const char& c: t_value)
  {
    if(!std::isalpha(c))
    {
        throw std::invalid_argument("Invalid character in Name");
    }
  }
  value = t_value;

}
