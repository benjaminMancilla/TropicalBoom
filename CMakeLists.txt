cmake_minimum_required(VERSION 3.0)
project(CGame)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# CMP0072 policy
if (POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

set(SOURCES ${SOURCES} ${PROJECT_SOURCE_DIR}/src/gl.c)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw)



