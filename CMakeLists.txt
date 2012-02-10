cmake_minimum_required (VERSION 2.6)
project (sfml-test)

find_package (SFML REQUIRED system window)
find_package (OpenGL REQUIRED)

if (APPLE)
  set (CMAKE_OSX_ARCHITECTURES "i386")
endif (APPLE)

add_executable (sfml-test main.cpp)

include_directories (${SFML_INCLUDE_DIRS})
include_directories (${OpenGL_INCLUDE_DIRS})
target_link_libraries (sfml-test ${SFML_LIBRARIES} "-framework OpenGL")
