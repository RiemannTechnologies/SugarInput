#include <gtest/gtest.h>

#include "../lib/IOStreamReader.h"
#include "../lib/IOStreamable.h"
using namespace Sugar::Input;
struct custom_data_type : public UserIOStreamable {
    int x;
    int y;
    int z;

    char m_TryRead(std::istream &_in) override {

        char err = SUGAR_INPUT_OK;
        m_IOStreamReader reader(_in);
        err = reader.m_TryRead(x);
        if (err)
            return err;
        err = reader.m_TryRead(y);
        if (err)
            return err;
        err = reader.m_TryRead(z);
        return err;
    }
};