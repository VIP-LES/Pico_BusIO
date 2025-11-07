cmake_minimum_required(VERSION 3.13)

add_library(ArduinoShim INTERFACE)
target_include_directories(ArduinoShim INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(ArduinoShim INTERFACE
    pico_stdlib
    ArduinoAPI
)
