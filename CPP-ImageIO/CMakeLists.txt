cmake_minimum_required(VERSION 3.16)
project(CPP_ImageIO)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPP_ImageIO BMPHeader.h BMPHeader.cpp Image.h Image.cpp image_io_test.cpp)