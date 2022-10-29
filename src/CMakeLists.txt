cmake_minimum_required(VERSION 3.14)
project(Graphics_Engine)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_BINARY_DIR
        ../bin)

set(EXECUTABLE_OUTPUT_PATH
        ${PROJECT_BINARY_DIR})

set(shared_source
        easy_image.cc
        ini_configuration.cc
        l_parser.cc Line2D.cpp Point2D.cpp)

set(release_source)

set(debug_source intro.cpp Color.cpp Line2D.cpp)

add_executable(engine
        ${shared_source}
        ${release_source}
        ./Release/main.cpp)

add_executable(dbg_engine
        ${shared_source}
        ${debug_source}
        ./Debug/main.cpp
)
