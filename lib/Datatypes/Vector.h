#pragma once
#include "IOStreamable.h"
#include <vector>
#include "IOStreamReader.h"
#include "Container.h"
namespace Sugar::Input{

  template <IOStreamable T>
  struct Vector : UserIOStreamable, Containter
  {
    std::vector<T> data;
    raw_input Read(std::istream* input) override
    {
      return Reader::Read(input);
    }
    void Parse(raw_input input) override
    {
      for (auto& item : input)
      {
        T t;
        Parser::Parse(t, item);
        data.emplace_back(t);
      }
    }
  };

}