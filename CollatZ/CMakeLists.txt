# CMakeList.txt : CMake project for CollatZ, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.25.0)

project ("CollatZ" C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_C_STANDARD_REQUIRED 17)


# Add source to this project's executable.
add_executable (CollatZ "CollatZ.cpp" "CollatZ.h" "basic.hpp" "gterm.hpp" "verify.hpp")


# TODO: Add tests and install targets if needed.
