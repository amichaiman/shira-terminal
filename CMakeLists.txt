cmake_minimum_required(VERSION 3.9)
project(shira_terminal)

set(CMAKE_CXX_STANDARD 11)

add_executable(shira_terminal main.cpp Terminal.cpp Terminal.h mainFunctions.cpp mainFunctions.h File.cpp File.h)