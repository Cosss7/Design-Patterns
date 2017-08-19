cmake_minimum_required(VERSION 3.7)
project(Design_Patterns)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp AbstractFactory.h Builder.h FactoryMethod.h Prototype.h Singleton.h Adapter.h)
add_executable(Design_Patterns ${SOURCE_FILES})