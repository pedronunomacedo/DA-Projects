cmake_minimum_required(VERSION 3.20)
project(project2_DA)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    project2_DA 
    src/main.cpp 
    include/graph.h src/graph.cpp  
    include/menu.h  src/menu.cpp 
    include/Scenario1.h  src/Scenario1.cpp 
    include/Scenario2.h src/Scenario2.cpp
)
