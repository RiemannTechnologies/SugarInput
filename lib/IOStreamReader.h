#pragma once

#include "impl/m_IOStreamReader.h"
#include "IOException.h"
namespace sugar
{
    class IOStreamReader{
        m_IOStreamReader ioStreamReader;
    public:
        explicit IOStreamReader(std::istream& _in) : ioStreamReader(_in){}
        template<IOStreamable T>
        void TryRead(T& x){
            char err = ioStreamReader.m_TryRead(x);
            if(!err)
                return;
            else
                throw IOException(err);
        }

    };


}
