#pragma once

#include "Reader.h"
#include "Parser.h"
namespace Sugar::Input {

    class IOStreamReader {



        std::istream *input;
     public:
        explicit IOStreamReader(std::istream& _in) : input(&_in) {}

        template<IOStreamable T>
        T Read() {
            T result;
            if constexpr (!std::is_base_of_v<UserIOStreamable, T>)//make this less sobful
            {
                Parser::Parse(result,Reader::Read(input)[0]);
            }
            else
            {
                Parser::Parse(result,Reader::Read(input));
            }
            return result;
        }


    };

} // Sugar

