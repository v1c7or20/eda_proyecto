cmake_minimum_required(VERSION 3.19)
project(EDA_proyecto)

set(CMAKE_CXX_STANDARD 14)

add_executable(EDA_proyecto main.cpp punto.cpp viajes.cpp barrio.cpp barrio.h barrios_parser.cpp barrios_parser.h)