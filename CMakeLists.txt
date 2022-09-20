
cmake_minimum_required(VERSION 3.15)
project(FinalProject)
add_executable(FinalProject src/helloSFML.cpp src/gameWindow.cpp)
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(FinalProject sfml-graphics)
target_compile_options(FinalProject PUBLIC -std=c++17)
