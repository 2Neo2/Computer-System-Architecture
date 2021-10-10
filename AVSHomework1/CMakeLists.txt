cmake_minimum_required(VERSION 3.20)
project(AVSHomework1)

set(CMAKE_CXX_STANDARD 14)

add_executable(AVSHomework1 main.cpp "Plants/Files-with-cpp/flower.cpp" "Plants/Files-with-h/flower.h" "Plants/Files-with-cpp/shrub.cpp" "Plants/Files-with-h/shrub.h" "Plants/Files-with-cpp/tree.cpp" "Plants/Files-with-h/tree.h" "Plants/Files-with-cpp/plant.cpp" "Plants/Files-with-h/plant.h" "Plants/Files-with-cpp/container.cpp" "Plants/Files-with-h/container.h" "Plants/Files-with-cpp/randomGenerator.cpp" "Plants/Files-with-h/randomGenerator.h" "Plants/Files-with-h/constants.h")
