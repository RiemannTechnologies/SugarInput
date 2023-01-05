//
// Created by thonk on 30.10.2022.
//

#include "m_IOStreamReader.h"
#include "../IOException.h"

namespace Sugar::Input {

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
        char result = x.m_TryRead(*input);
        return result;
    }

    void m_IOStreamReader::skip(unsigned times)
    {
        for(int i=1; i<=times; i++)
            skip();
    }
    void m_IOStreamReader::skip() {
        input->clear();
        char c;
        do{
            input->get(c);
            //handle quotes
            if(c == '\"')
            {
                do{
                    input->get(c);
                }
                while(c != '\"' && !input->eof());
                if(c!= '\"')
                {
                    throw IOException(SUGAR_INPUT_INVALID_CONTENT, "Unbalanced quotes");
                }
            }
        }
        while(this->skipChars.find(c) == std::string::npos && !input->eof());
    }

    void m_IOStreamReader::discard_line() {
        input->ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char m_IOStreamReader::m_TryRead(std::string &x) {
        char result = SUGAR_INPUT_OK;
        *input >> std::quoted(x);
        if(input->bad()){
            result |= SUGAR_INPUT_UNKNOWN_ERROR;
        }
        return result;
    }
    char m_IOStreamReader::m_TryRead(double &x) {
        char result = SUGAR_INPUT_OK;
        std::string _tmp;
        *input >> _tmp;

        if(input->bad()){
            result |= SUGAR_INPUT_UNKNOWN_ERROR;
        }

        try {
            x = std::stod(_tmp);
        } catch (std::invalid_argument &e) {
            result |= SUGAR_INPUT_INVALID_CONTENT;
        } catch (std::out_of_range &e) {
            result |= SUGAR_INPUT_OUT_OF_RANGE;
        }
        return result;
    }
    char m_IOStreamReader::m_TryRead(float &x) {
        char result = SUGAR_INPUT_OK;
        std::string _tmp;
        *input >> _tmp;

        if(input->bad()){
            result |= SUGAR_INPUT_UNKNOWN_ERROR;
        }

        try {
            x = std::stof(_tmp);
        } catch (std::invalid_argument &e) {
            result |= SUGAR_INPUT_INVALID_CONTENT;
        } catch (std::out_of_range &e) {
            result |= SUGAR_INPUT_OUT_OF_RANGE;
        }
        return result;
    }
} // Sugar