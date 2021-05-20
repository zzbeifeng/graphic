cmake_minimum_required(VERSION 3.0.0)
project(kkcore)

# find the required packages
find_package(GLM REQUIRED)
message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")
find_package(GLFW3 REQUIRED)
message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")
find_package(ASSIMP REQUIRED)
message(STATUS "Found ASSIMP in ${ASSIMP_INCLUDE_DIR}")
find_package (glog 0.5.0 REQUIRED)

INCLUDE_DIRECTORIES(/System/Library/Frameworks)

#定义库
SET(APPLE_LIBS ${APPLE_LIBS} ${GLFW3_LIBRARY})
set(LIBS ${LIBS} ${APPLE_LIBS})

add_library(kkcore kkApplication.cpp kkWindow.cpp)

target_link_libraries(kkcore "glfw")
target_link_libraries(kkcore ${LIBS})
target_link_libraries (kkcore glog::glog)

# include_directories(${CMAKE_SOURCE_DIR}/includes)