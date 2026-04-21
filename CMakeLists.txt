cmake_minimum_required(VERSION 3.10)

project(SmartHome VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include all header directories
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/Lights
    ${CMAKE_SOURCE_DIR}/Thermostats
    ${CMAKE_SOURCE_DIR}/Cameras
    ${CMAKE_SOURCE_DIR}/Commands
    ${CMAKE_SOURCE_DIR}/State
)

# Only source file is main.cpp (all other files are headers)
add_executable(SmartHome main.cpp)
