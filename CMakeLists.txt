cmake_minimum_required(VERSION 3.23)
project(SugarInput)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(include/spdlog)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
file(GLOB LIB_SRC
        lib/*.cpp
        lib/impl/*.cpp)

file(GLOB LIB_TESTS
        tests/*.cpp)
add_library(SugarInput SHARED ${LIB_SRC})
add_executable(SugarInput_TEST ${LIB_SRC} ${LIB_TESTS})
target_include_directories(SugarInput PUBLIC
        "include/")
target_include_directories(SugarInput_TEST PUBLIC
        "include/")
target_compile_definitions(SugarInput_TEST PRIVATE GTEST_COLOR=yes)

target_link_libraries(SugarInput PRIVATE spdlog)
target_link_libraries(SugarInput_TEST PRIVATE spdlog gtest_main)

include(GoogleTest)
gtest_discover_tests(SugarInput_TEST)