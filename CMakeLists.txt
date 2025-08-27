cmake_minimum_required(VERSION 3.10)

project(fractal_renderer
    LANGUAGES CXX
    VERSION 1.0
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory(src)
add_subdirectory(libs)
target_include_directories(fractal_renderer PRIVATE include)

