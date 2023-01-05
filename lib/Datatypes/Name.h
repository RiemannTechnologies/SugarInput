#pragma once
#include "../IOStreamable.h"
#include "../IOStreamReader.h"
#include "../Constants.h"
namespace Sugar::Input{

  struct Name : UserIOStreamable
  {
    std::string value;
    char m_TryRead(std::istream &_in) override;
  };
}