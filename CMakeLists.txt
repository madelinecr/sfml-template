cmake_minimum_required (VERSION 2.6)
project (sfml-test)

set (CMAKE_FIND_FRAMEWORK "NEVER")
find_package (SFML REQUIRED system window)
set (CMAKE_FIND_FRAMEWORK "ONCE")
find_package (OpenGL REQUIRED)

add_executable (sfml-test main.cpp)

include_directories (${SFML_INCLUDE_DIRS})
include_directories (${OpenGL_INCLUDE_DIRS})

target_link_libraries (sfml-test ${SFML_LIBRARIES})

if (APPLE)
  target_link_libraries (sfml-test "-framework OpenGL")
elseif (LINUX)
  target_link_libraries(sfml-test ${OpenGL_LIBRARIES})
endif ()
