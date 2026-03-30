cmake_minimum_required(VERSION 4.0)
project(snowflake)
set(CMAKE_CXX_STANDARD 23)

add_executable(snowflake main.cpp)

find_package(SFML COMPONENTS
        network
        graphics
        window
        audio REQUIRED)
target_link_libraries(snowflake
        sfml-network
        sfml-graphics
        sfml-window
        sfml-audio)