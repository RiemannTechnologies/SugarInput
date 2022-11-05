#pragma once

#include "impl/m_IOStreamReader.h"
#include "IOException.h"
namespace sugar
{

    class IOStreamReader{
        m_IOStreamReader ioStreamReader;
        bool m_skipInvalidInput = false;
    public:
        explicit IOStreamReader(std::istream& _in) : ioStreamReader(_in){}

        template<IOStreamable T>
        void TryRead(T& x){
            char err = 0;
            do {
                err = ioStreamReader.m_TryRead(x);
                if (!err)
                    return;
                else if (!m_skipInvalidInput)
                    throw IOException(err);
                else {
                    ioStreamReader.skip();
                }
            }
            while(m_skipInvalidInput && err && ioStreamReader.input->peek()!=EOF);
            if(ioStreamReader.input->peek() == EOF)
            {
                throw IOException(err);
            }
        }

        IOStreamReader& skip_invalid_input(bool value)
        {
            m_skipInvalidInput = value;
            return *this;
        }

    };


}
