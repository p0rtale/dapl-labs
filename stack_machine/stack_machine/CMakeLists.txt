get_filename_component(LIB_INCLUDE_PATH ".." ABSOLUTE)

file(GLOB_RECURSE SOURCES *.cpp)

add_library(stack_machine STATIC ${SOURCES})
target_include_directories(stack_machine PUBLIC ${LIB_INCLUDE_PATH})
