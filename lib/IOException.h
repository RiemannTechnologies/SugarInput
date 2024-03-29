#pragma once
#include <exception>
#include <string>
#include "Constants.h"

#define SUGAR_INPUT_OUT_OF_RANGE_STR "The data provided is out of range."
#define SUGAR_INPUT_INVALID_CONTENT_STR "The data provided is invalid."
#define SUGAR_INPUT_UNKNOWN_ERROR_STR "An unknown error occurred."
namespace Sugar::Input {
    class IOException : std::exception {
        std::string message;
        char code;
        private:
        void build_error_msg(int &errCode);
    public:
        explicit IOException(int errCode) : code(errCode) {
            build_error_msg(errCode);
        }

        explicit IOException(int errCode, std::string user_error_msg): code(errCode) {
            if(errCode == SUGAR_INPUT_OK)
                return;
            if(errCode & SUGAR_INPUT_USER_ERROR)
                message += user_error_msg;
            build_error_msg(errCode);
        }
        [[nodiscard]] const char *what() const noexcept override {
            return message.c_str();
        }
    };
}

