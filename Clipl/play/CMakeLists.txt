add_executable(parse parse.cpp)
target_link_libraries(parse clipl)

add_executable(preprocess preprocess.cpp)
target_link_libraries(preprocess clipl)
