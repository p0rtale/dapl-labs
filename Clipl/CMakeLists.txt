cmake_minimum_required(VERSION 3.20)
project(Clipl)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
find_package(spdlog REQUIRED)

# add_compile_options(-Wall -Wextra -Wpedantic -Werror -fPIC)
add_compile_options(-fPIC)

add_subdirectory(Clipl)
add_subdirectory(play)
