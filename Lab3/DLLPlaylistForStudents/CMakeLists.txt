cmake_minimum_required(VERSION 3.10)
project(DLLPlaylistForStudents)

set(CMAKE_CXX_STANDARD 17)

add_executable(MainDLL MainDLL.cpp DLL.cpp DNode.cpp)