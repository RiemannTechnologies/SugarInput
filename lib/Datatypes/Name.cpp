#include "Name.h"

char Sugar::Input::Name::m_TryRead(std::istream &_in) {
  m_IOStreamReader reader(_in);
  char retval =  reader.m_TryRead(value);

  for(const char& c: value)
  {
    if(!std::isalpha(c))
    {
      retval |= SUGAR_INPUT_INVALID_CONTENT;
      break;
    }
  }
  return retval;
}
