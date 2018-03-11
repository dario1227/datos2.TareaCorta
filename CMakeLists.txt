cmake_minimum_required(VERSION 3.9)
project(datos2.TareaCorta)

set(CMAKE_CXX_STANDARD 11)

add_executable(datos2.TareaCorta main.cpp QuickSort/QuickSort.cpp QuickSort/QuickSort.h "txt Maker/maker.cpp" "txt Maker/maker.h" "txt Maker/BigArray.cpp" "txt Maker/BigArray.h")