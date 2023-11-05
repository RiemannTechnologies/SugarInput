//
// Created by iPad Pro on 09/01/2023.
//

#include "Reader.h"
#include "Constants.h"
#include "IOException.h"
#include <sstream>
#include <iomanip>
namespace Sugar::Input {
    raw_input Reader::Read(std::istream *input_stream) {
        std::string _tmp;
        std::string line;
        raw_input result;
        std::getline(*input_stream,line,'\n');
        std::istringstream linestream(line);

        while(linestream>>std::quoted(_tmp))
        {
            result.emplace_back(_tmp);
        }
        if(input_stream->bad()){
            throw IOException(SUGAR_INPUT_UNKNOWN_ERROR);
        }
        return result;
    }
}