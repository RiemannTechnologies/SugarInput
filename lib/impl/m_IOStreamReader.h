#pragma once
#include <istream>
#include "../IOStreamable.h"
#include "../Constants.h"

namespace sugar {

    class m_IOStreamReader {
        std::istream *input;
    public:

        explicit m_IOStreamReader(std::istream& _input): input(&_input) {}
        char m_TryRead(int &x);
        char m_TryRead(char &x);
        char m_TryRead(unsigned &x);
        char m_TryRead(long long &x);
        char m_TryRead(unsigned long long &x);
        char m_TryRead(UserIOStreamable &x);
    };

} // sugar

