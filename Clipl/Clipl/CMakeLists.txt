get_filename_component(LIB_INCLUDE_PATH ".." ABSOLUTE)

file(GLOB_RECURSE LOGGER_SOURCES Logger/*.cpp)

BISON_TARGET(
    CliplParser
    ${CMAKE_SOURCE_DIR}/Clipl/Grammar/Parser/Parser.y
    ${CMAKE_SOURCE_DIR}/Clipl/Grammar/Parser/Parser.cpp
    DEFINES_FILE ${CMAKE_SOURCE_DIR}/Clipl/Grammar/Parser/Parser.hpp
    COMPILE_FLAGS "--graph -Wother -Wconflicts-sr"
    VERBOSE
)

FLEX_TARGET(
    CliplLexer
    ${CMAKE_SOURCE_DIR}/Clipl/Grammar/Lexer/Lexer.l
    ${CMAKE_SOURCE_DIR}/Clipl/Grammar/Lexer/Lexer.cpp
)

ADD_FLEX_BISON_DEPENDENCY(CliplLexer CliplParser)

file(GLOB_RECURSE DRIVER_SOURCES Grammar/Driver/*.cpp)

file(GLOB_RECURSE AST_SOURCES Grammar/AST/*.cpp)

add_library(
    clipl

    ${AST_SOURCES}
    ${DRIVER_SOURCES}
    ${BISON_CliplParser_OUTPUTS}
    ${FLEX_CliplLexer_OUTPUTS}
    ${LOGGER_SOURCES}
)

target_include_directories(clipl PUBLIC ${LIB_INCLUDE_PATH})

add_subdirectory(Preprocessor)

target_link_libraries(clipl PUBLIC preprocessor PRIVATE spdlog::spdlog)

# target_precompile_headers(clipl PRIVATE clpch.hpp)
