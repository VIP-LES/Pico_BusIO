cmake_minimum_required(VERSION 3.13)

add_library(Wire Wire.cpp)
target_include_directories(Wire PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Wire PUBLIC
    pico_stdlib
    hardware_i2c
    hardware_dma
    ArduinoShim
    ArduinoAPI
)
