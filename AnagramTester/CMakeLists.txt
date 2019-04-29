cmake_minimum_required(VERSION 3.12)
project(AnagramTester)

set(CMAKE_CXX_STANDARD 14)

add_executable(AnagramTester main.cpp AnagramSet.h LetterBag.h)