cmake_minimum_required(VERSION 3.5)
project(mario)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
include(FetchContent)

FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)

FetchContent_MakeAvailable(sfml)

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