cmake_minimum_required(VERSION 4.0)
project(mario)
set(CMAKE_CXX_STANDARD 23)

add_executable(mario main.cpp
        Hero.cpp
        Hero.h
        block.cpp
        block.h)

find_package(SFML COMPONENTS
        network
        graphics
        window
        audio REQUIRED)


target_link_libraries(mario
        sfml-network
        sfml-graphics
        sfml-window
        sfml-audio)