cmake_minimum_required(VERSION 3.15)
project(OOP_Example)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP_Example src/main.cpp src/Contact.h src/Contact.cpp
                           src/CommandHandler.h src/CommandHandler.cpp)
