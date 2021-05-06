cmake_minimum_required(VERSION 3.19)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
include_directories(.)
add_executable(ft_containers
        main.cpp)

add_executable(Deque
        Deque/main.cpp
        )

add_executable(Vector
        Vector/main.cpp
        )
