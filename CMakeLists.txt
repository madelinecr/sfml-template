cmake_minimum_required (VERSION 2.6)
project (sfml-test)

find_package(SFML)

add_executable(sfml-test main.cpp)

include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(sfml-test ${SFML_LIBRARIES})
