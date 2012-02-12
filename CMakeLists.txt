# Project Settings
cmake_minimum_required (VERSION 2.6)
project (sfml-test)

set (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Modules)

# Libraries
set (CMAKE_FIND_FRAMEWORK "NEVER")
find_package (SFML REQUIRED system window)
set (CMAKE_FIND_FRAMEWORK "ONCE")
find_package (OpenGL REQUIRED)

# Build Settings
set (EXECUTABLE "sfml-test")
set (SRC_FILES "main.cpp")
set (PROJECT_INCLUDES ${SFML_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})


# Build setup
add_executable (${EXECUTABLE} ${SRC_FILES})

include_directories (${PROJECT_INCLUDES})
target_link_libraries (${EXECUTABLE} ${SFML_LIBRARIES})

if (APPLE)
  message ( "Apple environment detected. Binding to OpenGL framework." )
  target_link_libraries (${EXECUTABLE} "-framework OpenGL")
else ()
  message ( "Assuming POSIX environment and binding with OpenGL." )
  target_link_libraries (${EXECUTABLE} ${OPENGL_LIBRARIES})
endif ()
