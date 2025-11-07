# Pico_BusIO Library
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

add_subdirectory(lib)

add_library(pico_busio 
    src/Adafruit_BusIO_Register.cpp 
    src/Adafruit_GenericDevice.cpp 
    src/Adafruit_I2CDevice.cpp 
    src/Adafruit_SPIDevice.cpp
)
target_include_directories(pico_busio PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
target_link_libraries(pico_busio PUBLIC
    ArduinoShim
    Wire
    SPI
)