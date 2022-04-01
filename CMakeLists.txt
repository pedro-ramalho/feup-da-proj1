cmake_minimum_required(VERSION 3.17)
project(DA2122_PROJ1)

file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(src main.cpp ${SRC_FILES})