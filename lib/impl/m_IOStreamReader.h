#pragma once
#include <istream>
#include <iomanip>
#include <limits>
#include <regex>
#include "../IOException.h"
#include "../IOStreamable.h"
#include "../Constants.h"
namespace Sugar::Input {

    struct m_IOStreamReader {

        const std::string skipChars = " \n";
        const std::regex signedNumberFilter = std::regex("^-?\\d+$");
        const std::regex unsignedNumberFilter = std::regex("^\\d+$");
        const std::regex signedDecimalFilter = std::regex(R"(^-?\d+(\.\d+)?$)");
        const std::regex unsignedDecimalFilter = std::regex(R"(^\d+(\.\d+)?$)");

        std::istream *input;
        explicit m_IOStreamReader(std::istream& _in) : input(&_in) {}

        char m_TryRead(int &x);
        char m_TryRead(char &x);
        char m_TryRead(unsigned &x);
        char m_TryRead(long long &x);
        char m_TryRead(unsigned long long &x);
        char m_TryRead(double &x);
        char m_TryRead(float &x);
        char m_TryRead(std::string &x) const;
        char m_TryRead(UserIOStreamable &x) const;

        void skip();
        void skip(unsigned times);
        void discard_line() const;
    };

} // Sugar

