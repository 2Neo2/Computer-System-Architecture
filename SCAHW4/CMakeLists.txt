cmake_minimum_required(VERSION 3.20)
project(SCAHW4)

set(CMAKE_CXX_STANDARD 14)

add_executable(SCAHW4 main.c "plant.c" "header_files/plant.h" "container.c" "header_files/container.h" "rnd.c" "header_files/rnd.h" "header_files/constants.h")
