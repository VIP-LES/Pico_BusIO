cmake_minimum_required(VERSION 3.13)
add_library(SPI SPI.cpp)
target_include_directories(SPI PUBLIC ${CMAKE_CURRENT_LIST_DIR})
# Ensure SPI target is built with C++20
set_target_properties(SPI PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)
target_compile_features(SPI PUBLIC cxx_std_20)
target_link_libraries(SPI PUBLIC
    pico_stdlib
    hardware_spi
    hardware_dma
    hardware_irq
    hardware_gpio
    ArduinoAPI
    ArduinoShim
)
