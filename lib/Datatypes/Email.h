#pragma once
#include "../IOStreamable.h"
#include "IOStreamReader.h"
#include "../Constants.h"
#include <regex>
namespace Sugar::Input {

    struct Email : UserIOStreamable
    {
      std::string value;
      raw_input Read(std::istream *input) override;
      void Parse(raw_input _input) override;
    };
}