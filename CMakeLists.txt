# Vaš kod dolazi ovdje.

cmake_minimum_required(VERSION 3.18)
project(Ranges)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(main main.cpp)
set(range-v3_DIR "/home/sime1997/napredni_cpp/ranges-sime1997/vcpkg/packages/range-v3_x64-linux/share/range-v3")
find_package(range-v3 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED) 
target_link_libraries(main PRIVATE fmt)
target_link_libraries(main PRIVATE range-v3 range-v3-meta range-v3::meta range-v3-concepts)
