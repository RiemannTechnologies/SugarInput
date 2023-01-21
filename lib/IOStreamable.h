#pragma once
#include <string>
#include <vector>
#include <istream>
#include "Reader.h"
#include "Constants.h"
namespace Sugar::Input{


  struct UserIOStreamable{

    virtual raw_input Read(std::istream* input)
    {
      return Reader::Read(input);
    };
    virtual void Parse(raw_input _input) = 0;
  };
  template<typename T>
  concept IOStreamable =  std::is_same_v<T, int> ||
      std::is_same_v<T, unsigned int> ||
      std::is_same_v<T, long long> ||
      std::is_same_v<T, unsigned long long>  ||
      std::is_same_v<T, char> ||
      std::is_same_v<T, std::string> ||
      std::is_base_of_v<UserIOStreamable,T>;

}