#pragma once
#include <istream>
#include <limits>
#include <iomanip>
#include "../IOStreamable.h"
#include "../Constants.h"
namespace sugar {

    struct m_IOStreamReader {

        const std::string skipChars = " \n";
        std::istream *input;
        explicit m_IOStreamReader(std::istream& _in) : input(&_in) {}

        char m_TryRead(int &x);
        char m_TryRead(char &x);
        char m_TryRead(unsigned &x);
        char m_TryRead(long long &x);
        char m_TryRead(unsigned long long &x);
        char m_TryRead(std::string &x);
        char m_TryRead(UserIOStreamable &x);

        void skip();
        void skip(unsigned times);
        void discard_line();
    };

} // sugar

