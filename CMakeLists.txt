cmake_minimum_required(VERSION 3.10)

project(ProgramowanieObiektowe)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/ProgramowanieObiektowe)
include(CheckCXXCompilerFlag)
include(AddFileDependencies)

file(GLOB_RECURSE SRCS ProgramowanieObiektowe/*.cpp)
file(GLOB_RECURSE HDRS ProgramowanieObiektowe/*.hpp)
file(GLOB_RECURSE REMOVE_CMAKE "cmake-build-debug/*")
list(REMOVE_ITEM your_list_of_sources ${REMOVE_CMAKE})
add_executable(ProgramowanieObiektowe.out ${SRCS} ${HDRS})
