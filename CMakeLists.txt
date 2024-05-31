cmake_minimum_required(VERSION 3.24)
project(OOP_2024)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_2024 main.cpp)

add_executable(zad1 mk/av13/zad1.cpp)
add_executable(zad2 mk/av13/zad2.cpp)
add_executable(zad3 mk/av12/zad3.cpp)
add_executable(zad4 mk/av12/zad4.cpp)
add_executable(zad5 mk/av12/zad5.cpp)


add_executable(task1 en/ex13/task1.cpp)
add_executable(task2 en/ex13/task2.cpp)
add_executable(task3 en/ex12/task3.cpp)
add_executable(task4 en/ex12/task4.cpp)
add_executable(task5 en/ex12/task5.cpp)
add_executable(task6 en/ex1/task6.cpp)

add_executable(playground playground.cpp)
