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
find_package(glm REQUIRED)
find_package(assimp REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw glm::glm assimp::assimp)

# Testing
enable_testing()
file(GLOB TEST_SOURCES tests/*.cpp ${PROJECT_SOURCE_DIR}/src/gl.c)
add_executable(test_suite ${TEST_SOURCES})
target_link_libraries(test_suite PRIVATE gtest gtest_main pthread OpenGL::GL glfw)
target_include_directories(test_suite PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME RunTests COMMAND test_suite)



