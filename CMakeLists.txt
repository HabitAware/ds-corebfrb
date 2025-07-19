cmake_minimum_required(VERSION 3.10)

project(ds_corebfrb C)

# Use C11 standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Core library
add_library(corebfrb
    motion_algo/core/corebfrb.c
)

target_include_directories(corebfrb PUBLIC
    motion_algo/core
)

# Test executable
add_executable(corebfrb_test
    motion_algo/test/main.c
)

target_include_directories(corebfrb_test PRIVATE
    motion_algo/test
    motion_algo/core
)

target_link_libraries(corebfrb_test PRIVATE corebfrb)

# Link math library on platforms that need it (e.g., Linux, macOS)
if(NOT WIN32)
    target_link_libraries(corebfrb_test PRIVATE m)
endif() 