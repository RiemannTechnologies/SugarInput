#pragma once
#include "../IOStreamable.h"
#include "IOStreamReader.h"
#include "../Constants.h"
namespace Sugar::Input{

  struct Name : UserIOStreamable
  {
    std::string value;
    void Parse(raw_input _input) override;
  };
}