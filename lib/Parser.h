#pragma once
#include <cstdint>
#include "IOStreamable.h"
#include <regex>
namespace Sugar::Input {



  class Parser {

    static const inline std::regex signedNumberFilter = std::regex(R"(^-?\d+$)");
    static const inline std::regex unsignedNumberFilter = std::regex(R"(^\d+$)");
    static const inline std::regex signedDecimalFilter = std::regex(R"(^-?\d+(\.\d+)?$)");
    static const inline std::regex unsignedDecimalFilter = std::regex(R"(^\d+(\.\d+)?$)");
   public:
    static void Parse(std::int32_t &destination, std::string_view input);
    static void Parse(std::uint32_t &destination, std::string_view input);
    static void Parse(std::int64_t &destination, std::string_view input);
    static void Parse(std::uint64_t &destination, std::string_view input);
    static void Parse(std::string &destination, std::string_view input);
    static void Parse(double &destination, std::string_view input);
    static void Parse(float &destination, std::string_view input);
    static void Parse(char &destination, std::string_view input);
	static void Parse(bool& destination, std::string_view input);
    static void Parse(UserIOStreamable& destination, raw_input input);
  };

} // Input
