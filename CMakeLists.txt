cmake_minimum_required(VERSION 3.19)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

include_directories(.
        Iterator
        test_runner
        Vector
        Vector/unit_tests_vector
        List
        List/unit_tests_list
        )

add_executable(ft_containers
        main.cpp)

add_executable(Deque
        Deque/main.cpp
        )

add_executable(Vector
        Vector/main.cpp
        )

add_executable(List
        List/main.cpp
        )

add_executable(testiter
        Iterator/testRandom.cpp
        )
