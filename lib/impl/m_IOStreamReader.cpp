//
// Created by thonk on 30.10.2022.
//

#include "m_IOStreamReader.h"

namespace sugar {

    char m_IOStreamReader::m_TryRead(int &x) {
        char result = SUGAR_INPUT_OK;
        std::string _tmp;
        *input >> _tmp;

        if(input->bad()){
            result |= SUGAR_INPUT_UNKNOWN_ERROR;
        }

        try {
            x = std::stoi(_tmp);
        } catch (std::invalid_argument &e) {
            result |= SUGAR_INPUT_INVALID_CONTENT;
        } catch (std::out_of_range &e) {
            result |= SUGAR_INPUT_OUT_OF_RANGE;
        }
        return result;
    }

    char m_IOStreamReader::m_TryRead(char &x) {
        char result = SUGAR_INPUT_OK;
        std::string _tmp;
        *input >> _tmp;

        if(input->bad()){
            result |= SUGAR_INPUT_UNKNOWN_ERROR;
        }

        if (_tmp.length() > 1) {
            result |= SUGAR_INPUT_INVALID_CONTENT;
            if(!(_tmp[0] <= 127 && _tmp[0] >= -128))
            {
                result |= SUGAR_INPUT_OUT_OF_RANGE;
            }
        }
        else
        {
            x = _tmp[0];
        }
        return result;

    }
    char m_IOStreamReader::m_TryRead(unsigned int &x) {
        char result = SUGAR_INPUT_OK;
        std::string _tmp;
        *input >> _tmp;

        if(input->bad()){
            result |= SUGAR_INPUT_UNKNOWN_ERROR;
        }

        try {
            x = std::stoul(_tmp);
        } catch (std::invalid_argument &e) {
            result |= SUGAR_INPUT_INVALID_CONTENT;
        } catch (std::out_of_range &e) {
            result |= SUGAR_INPUT_OUT_OF_RANGE;
        }
        return result;
    }

    char m_IOStreamReader::m_TryRead(long long  &x) {
        char result = SUGAR_INPUT_OK;
        std::string _tmp;
        *input >> _tmp;

        if(input->bad()){
            result |= SUGAR_INPUT_UNKNOWN_ERROR;
        }

        try {
            x = std::stoll(_tmp);
        } catch (std::invalid_argument &e) {
            result |= SUGAR_INPUT_INVALID_CONTENT;
        } catch (std::out_of_range &e) {
            result |= SUGAR_INPUT_OUT_OF_RANGE;
        }
        return result;
    }

    char m_IOStreamReader::m_TryRead(unsigned long long  &x) {
        char result = SUGAR_INPUT_OK;
        std::string _tmp;
        *input >> _tmp;

        if(input->bad()){
            result |= SUGAR_INPUT_UNKNOWN_ERROR;
        }

        try {
            x = std::stoull(_tmp);
        } catch (std::invalid_argument &e) {
            result |= SUGAR_INPUT_INVALID_CONTENT;
        } catch (std::out_of_range &e) {
            result |= SUGAR_INPUT_OUT_OF_RANGE;
        }
        return result;
    }

    char m_IOStreamReader::m_TryRead(UserIOStreamable &x) {
        char result = SUGAR_INPUT_OK;
        x.m_TryRead(result);
        return result;
    }

    void m_IOStreamReader::skip() {
        input->clear();
        while(this->skipChars.find(input->peek()) == std::string::npos || !input->eof())
        {
            input->ignore(1);
        }
    }
} // sugar