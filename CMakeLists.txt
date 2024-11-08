cmake_minimum_required(VERSION 3.25)

project(
  Cvazz
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_COMPILER "clang++")

file(GLOB_RECURSE SRC_FILES src/*)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_compile_options(
  -O3
  -flto
  -funroll-loops
  -fno-exceptions
  -march=native
  -Wall
  -Wextra
  -pedantic
)

add_link_options(
  -flto
)

add_executable(Cvazz ${SRC_FILES})

target_link_libraries(Cvazz)
