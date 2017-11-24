cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/Polly-99/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "76f92ff7b49ec643196e60690f2123c3b986cdb7"
)

project(lab13)

hunter_add_package(yaml-cpp)
find_package(yaml-cpp CONFIG REQUIRED)

add_executable(pack ${CMAKE_CURRENT_SOURCE_DIR}/sources/pack.cpp)
target_link_libraries(pack yaml-cpp::yaml-cpp)

