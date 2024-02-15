set(EXECUTABLE_NAME PathWiz)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(PathWiz VERSION 1.0.0)
add_executable(
    "${EXECUTABLE_NAME}"
    src/main.cpp
    src/Node.h
    src/Button.h
    src/Graph.h
    )

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries("${EXECUTABLE_NAME}" sfml-system sfml-window sfml-graphics sfml-audio sfml-network)