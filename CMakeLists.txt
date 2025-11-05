# Adafruit Bus IO Library
# https://github.com/adafruit/Adafruit_BusIO
# MIT License

cmake_minimum_required(VERSION 3.13)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# If we are the root project (for compile testing)
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)

    # Pull in Pico SDK
    include(pico_sdk_import)

    project(Pico_BusIO C CXX ASM)

    pico_sdk_init()

endif()

# Require modern C++ (C++20) for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(ArduinoCore-API)

add_subdirectory(ArduinoShim)
add_subdirectory(SPI)
add_subdirectory(Wire)

file(GLOB SRC_FILES
    *.cpp
)

add_library(Pico_BusIO ${SRC_FILES})
target_include_directories(Pico_BusIO PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Pico_BusIO PRIVATE
    pico_stdlib
    Wire
    ArduinoShim
    SPI
)
