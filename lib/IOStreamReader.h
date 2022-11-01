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
            char err = ioStreamReader.m_TryRead(x);
            if(!err)
                return;
            else
                if(!m_skipInvalidInput)
                    throw IOException(err);
                else
                    ioStreamReader.skip();
        }

        IOStreamReader& skip_invalid_input(bool value)
        {
            m_skipInvalidInput = value;
            return *this;
        }
        IOStreamReader& for_input(std::istream& _in)
        {
            ioStreamReader.input = &_in;
            return *this;
        }

    };


}
