cmake_minimum_required(VERSION 3.23)
project(SugarInput)

set(CMAKE_CXX_STANDARD 20)


file(GLOB_RECURSE LIB_SRC
        lib/*.cpp)
enable_testing()
add_library(SugarInput SHARED ${LIB_SRC})


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
    file(GLOB LIB_TESTS
            tests/*.cpp)
    add_executable(SugarInput_TEST ${LIB_SRC} ${LIB_TESTS})
    target_link_libraries(SugarInput_TEST PRIVATE gtest_main)
    target_compile_definitions(SugarInput_TEST PRIVATE GTEST_COLOR=yes)
    include(GoogleTest)
    gtest_discover_tests(SugarInput_TEST)
endif()