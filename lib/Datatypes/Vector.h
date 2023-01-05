#pragma once
#include "../IOStreamable.h"
#include <vector>
#include "../IOStreamReader.h"
namespace Sugar::Input{

  template <IOStreamable T>
  struct Vector : UserIOStreamable
  {
    std::vector<T> data;
    char m_TryRead(std::istream& _in) override
    {
      std::string line;
      std::getline(_in,line);
      std::istringstream linestream(line);
      char result = SUGAR_INPUT_OK;
      m_IOStreamReader reader(linestream);

      while(result == SUGAR_INPUT_OK && !linestream.eof())
      {
        T _tmp;
        result = reader.m_TryRead(_tmp);
        data.emplace_back(_tmp);
      }
      if(result != SUGAR_INPUT_OK)
      {
        result|=SUGAR_INPUT_NOSKIP;
        data.erase();
      }
      return result;
    }
  };

}