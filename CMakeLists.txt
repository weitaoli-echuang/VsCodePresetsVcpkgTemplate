cmake_minimum_required(VERSION 3.15)

project(template VERSION 0.1.0)

find_package(benchmark CONFIG REQUIRED)

add_executable(template src/main.cpp)
target_compile_features(template PRIVATE cxx_std_20)
target_link_libraries(template PRIVATE benchmark::benchmark benchmark::benchmark_main)