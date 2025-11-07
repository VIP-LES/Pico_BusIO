# Adafruit Bus IO Library
# https://github.com/adafruit/Adafruit_BusIO
# MIT License

cmake_minimum_required(VERSION 3.13)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# If we are the root project (for compile testing)
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)

    # Pull in Pico SDK
    set(PICO_BOARD "pimoroni_pico_plus2_rp2350")
    include(pico_sdk_import)

    project(Pico_BusIO C CXX ASM)

    pico_sdk_init()

    include(Adafruit_BMP3XX)
    add_executable(main extra/src/main.cpp)
    target_link_libraries(main PUBLIC Adafruit_BMP3XX pico_stdlib)
    pico_enable_stdio_uart(main 0)
    pico_enable_stdio_usb(main 1)
    pico_add_extra_outputs(main)

endif()

# Require modern C++ (C++20) for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(lib)


add_library(Pico_BusIO 
    src/Adafruit_BusIO_Register.cpp 
    src/Adafruit_GenericDevice.cpp 
    src/Adafruit_I2CDevice.cpp 
    src/Adafruit_SPIDevice.cpp
)
target_include_directories(Pico_BusIO PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
target_link_libraries(Pico_BusIO PUBLIC
    ArduinoShim
    Wire
    SPI
)
