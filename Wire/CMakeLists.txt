cmake_minimum_required(VERSION 3.13)

add_library(Wire Wire.cpp)
target_include_directories(Wire PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Wire PUBLIC
    pico_stdlib
    pico_time
    hardware_i2c
    hardware_dma
    hardware_irq
    hardware_gpio
    ArduinoCore-API
    ArduinoShim
)
