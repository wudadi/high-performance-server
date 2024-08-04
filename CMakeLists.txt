cmake_minimum_required (VERSION 2.8)

project(high_perfomance_server)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 11)

message(${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
add_executable(main ${SRC_LIST})

find_package(Threads REQUIRED)
target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_compile_options(-std=c++11)
