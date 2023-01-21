#include <gtest/gtest.h>

#include "IOStreamReader.h"
#include "IOStreamable.h"
using namespace Sugar::Input;
struct custom_data_type : public UserIOStreamable {
    int x=0;
    int y=0;
    int z=0;

    void Parse(raw_input input) override {

        if(input.size() != 3)
            throw std::invalid_argument("Invalid input size");
        Parser::Parse(x,input[0]);
        Parser::Parse(y,input[1]);
        Parser::Parse(z,input[2]);
    }

};

TEST(custom_data_types, custom_data_type) {
    std::istringstream input("1 2 3");
    custom_data_type cdt;
    raw_input rin;
    ASSERT_NO_THROW(rin = cdt.Read(&input));
    ASSERT_NO_THROW(cdt.Parse(rin));
    ASSERT_EQ(cdt.x,1);
    ASSERT_EQ(cdt.y,2);
    ASSERT_EQ(cdt.z,3);
}
TEST(custom_data_types, custom_data_type_invalid_input) {
    std::istringstream input("1 2 3 4");
    custom_data_type cdt;
    raw_input rin;
    ASSERT_NO_THROW(rin = cdt.Read(&input));
    ASSERT_THROW(cdt.Parse(rin),std::invalid_argument);
}
TEST(custom_data_types, custom_data_type_invalid_input_2) {
    std::istringstream input("1 2");
    custom_data_type cdt;
    raw_input rin;
    ASSERT_NO_THROW(rin = cdt.Read(&input));
    ASSERT_THROW(cdt.Parse(rin),std::invalid_argument);
}