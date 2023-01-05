#pragma once
#include "../IOStreamable.h"
#include "../IOStreamReader.h"
#include "../Constants.h"
#include <regex>
namespace Sugar::Input {
  struct Email : UserIOStreamable {
    std::string value;
    char m_TryRead(std::istream &_in) override;
  };
}