//
// Created by thonk on 30.10.2022.
//

#include "IOException.h"

namespace Sugar::Input{
    void IOException::build_error_msg(int &errCode)
    {
        message += "IOException: ";
        if(errCode & SUGAR_INPUT_OUT_OF_RANGE){
            message += SUGAR_INPUT_OUT_OF_RANGE_STR;
        }
        if(errCode & SUGAR_INPUT_INVALID_CONTENT){
            message += SUGAR_INPUT_INVALID_CONTENT_STR;
        }
        if(errCode & SUGAR_INPUT_UNKNOWN_ERROR){
            message += SUGAR_INPUT_UNKNOWN_ERROR_STR;
        }
        message += " Error code: ";
        message += std::to_string(errCode);
    }
}