cmake_minimum_required(VERSION 3.25)
project(Algorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(Common)

add_executable(Algorithm
        Common/dataSet2.h
        Question1/Dataset1/main.cpp
        Question1/Dataset2/Coordinate.cpp
        Question1/Dataset2/DataSet2.cpp
        Question1/Dataset2/Edges.cpp
        Question1/Dataset2/Main.cpp
        Question1/Dataset2/Node.cpp
        Question2/HeapSort/main.cpp
        Question2/MergeSort/main.cpp
        Question3/Dijkstra'sAlgorithm/main.cpp
        Question3/Kruskal'sAlgorithm/main.cpp
        Question4/DynammicProgramming/main.cpp Question1/Dataset2/AdjacencyList.cpp)
