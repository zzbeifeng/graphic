cmake_minimum_required(VERSION 3.0.0)
project(kkGraphic VERSION 0.1.0)

include(CTest)

enable_testing()

add_definitions(-std=c++17)

option(TEST_DEBUG "option for debug" ON)
if (TEST_DEBUG) 
	add_definitions(-DTEST_DEBUG)
endif(TEST_DEBUG)

# kkgraphic root path
set(KKGRAPHIC_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-D KKDEBUG)

include_directories(src)
add_subdirectory(src output) 

include(src/geometry/CMakeLists.txt)

set(KKGRAPHIC_HEADER 
    ${Gemoetry_Head}
)

set(KKGRAPHIC_SRC main.cpp)

add_executable(kkGraphic ${KKGRAPHIC_SRC})
target_link_libraries(kkGraphic kkcore)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
