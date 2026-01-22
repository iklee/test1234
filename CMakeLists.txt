cmake_minimum_required(VERSION 3.10)
project(SimpleString)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files for the main library
set(LIBRARY_SOURCES
    src/string_utils.cpp
)

# Create library
add_library(simplestring STATIC ${LIBRARY_SOURCES})

# Main executable
add_executable(simplestring_app src/main.cpp)
target_link_libraries(simplestring_app simplestring)

# Test executable
enable_testing()
add_executable(test_runner tests/test_string_utils.cpp)
target_link_libraries(test_runner simplestring)

add_test(NAME StringUtilsTest COMMAND test_runner)
