#pragma once
#include <concepts>
#include <string>
namespace sugar{

    class UserIOStreamable{
    public:
        virtual UserIOStreamable m_TryRead(char& resFlag);
    };
    //concept that allows int, unsigned ints, long longs, unsigned long longs, chars, and strings and IOStreamable
    template<typename T>
    concept IOStreamable =  std::is_same_v<T, int> ||
                            std::is_same_v<T, unsigned int> ||
                            std::is_same_v<T, long long> ||
                            std::is_same_v<T, unsigned long long>  ||
                            std::is_same_v<T, char> ||
                            std::is_same_v<T, std::string> ||
                            std::is_base_of_v<UserIOStreamable,T>;
}