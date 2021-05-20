cmake_minimum_required(VERSION 3.0.0)
project(kkGraphic VERSION 0.1.0)

include(CTest)

enable_testing()

add_definitions(-std=c++17)

# kkgraphic root path
set(KKGRAPHIC_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(src)
add_subdirectory(src output) 

add_executable(kkGraphic main.cpp)
target_link_libraries(kkGraphic kkcore)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
