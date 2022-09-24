
cmake_minimum_required(VERSION 3.15)
project(blackjack)
add_executable(blackjack src/runGame.cpp src/gameWindow.cpp src/tests.cpp src/drawHelpers.cpp src/BlackjackScreens.cpp)
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(blackjack sfml-graphics sfml-audio)
target_compile_options(blackjack PUBLIC -std=c++17)
