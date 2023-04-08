cmake_minimum_required(VERSION 3.14)

project(stack_machine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

# option(WITH_TESTS "Build tests" YES)
# if(WITH_TESTS)
#     enable_testing()
#     find_package(GTest REQUIRED)
#     include(CTest)
# endif()

add_subdirectory(stack_machine)

# if(WITH_TESTS)
#     add_subdirectory(tests)
# endif()

add_subdirectory(play)
