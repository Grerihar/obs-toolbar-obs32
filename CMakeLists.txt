cmake_minimum_required(VERSION 3.16)

project(obs_toolbar)

set(CMAKE_CXX_STANDARD 17)

add_library(obs-toolbar MODULE
    src/obs-toolbar.cpp
    src/obs-toolbar.hpp
)

find_package(libobs REQUIRED)

target_link_libraries(obs-toolbar libobs)
