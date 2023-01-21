#pragma once
#include <istream>
#include "Constants.h"
namespace Sugar::Input {

    struct Reader {
        static raw_input Read(std::istream* input_stream);
    };
} // Input

