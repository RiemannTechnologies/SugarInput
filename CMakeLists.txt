cmake_minimum_required(VERSION 3.23)
project(SugarInput)

set(CMAKE_CXX_STANDARD 20)


enable_testing()
add_library(SugarInput SHARED lib/Parser.cpp lib/IOException.cpp lib/Datatypes/Email.cpp lib/Datatypes/Name.cpp lib/Datatypes/PhoneNumber.cpp lib/Reader.cpp lib/Reader.h lib/IOStreamable.h )
target_include_directories(SugarInput PRIVATE lib/)
target_include_directories(SugarInput PRIVATE lib/Datatypes)
target_include_directories(SugarInput PRIVATE lib/impl)

if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG release-1.12.1
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    add_executable(SugarInput_TEST lib/Parser.cpp lib/IOException.cpp lib/Datatypes/Email.cpp lib/Datatypes/Name.cpp lib/Datatypes/PhoneNumber.cpp
            tests/basic_io_test.cpp tests/custom_data_types.cpp tests/specialized_parser_test.cpp tests/string_test.cpp tests/vector_test.cpp tests/int32_tests.cpp tests/parser_test.h tests/uint32_tests.cpp tests/int64_test.cpp tests/uint64_test.cpp tests/char_test.cpp tests/float_test.cpp tests/double_test.cpp lib/IOStreamable.h lib/Reader.cpp lib/Reader.h)
    target_link_libraries(SugarInput_TEST PRIVATE gtest_main)
    target_include_directories(SugarInput_TEST PRIVATE lib/)
    target_compile_definitions(SugarInput_TEST PRIVATE GTEST_COLOR=yes)
    include(GoogleTest)
    gtest_discover_tests(SugarInput_TEST)
endif()