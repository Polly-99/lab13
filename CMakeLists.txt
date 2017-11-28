cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.167.tar.gz"
    SHA1 "244a13718ea2e6c0c8998d15559c7e459f615708"
    LOCAL
    )

project (lab13)

hunter_add_package(yaml-cpp)
find_package(yaml-cpp CONFIG REQUIRED)


add_executable(pack ${CMAKE_CURRENT_SOURCE_DIR}/sources/pack.cpp)
target_link_libraries(pack yaml-cpp::yaml-cpp)

add_executable(unpack ${CMAKE_CURRENT_SOURCE_DIR}/sources/unpack.cpp)
target_link_libraries(unpack yaml-cpp::yaml-cpp)

