cmake_minimum_required(VERSION 3.20)
project(project1_DA)
set(CMAKE_CXX_STANDARD 14)
include_directories(include)
file(GLOB SRC "src/*.cpp")
add_executable(
    main 
    src/main.cpp 
    ${SRC} 
    include/Courier.h src/Courier.cpp 
    include/Data.h src/Data.cpp
    include/Interface.h src/Interface.cpp
    include/Product.h src/Product.cpp
    include/Scenario1.h src/Scenario1.cpp 
    include/Scenario2.h src/Scenario2.cpp 
    include/Scenario3.h src/Scenario3.cpp 
)
