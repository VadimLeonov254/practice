cmake_minimum_required(VERSION 3.10)

project(matching_engine)

set(CMAKE_CXX_STANDARD 17)

add_executable(main matching_engine.cpp order.cpp)
