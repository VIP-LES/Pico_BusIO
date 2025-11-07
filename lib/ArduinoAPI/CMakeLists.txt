file(GLOB CPP_FILES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)

add_library(ArduinoAPI ${CPP_FILES})
target_link_libraries(ArduinoAPI PRIVATE pico_stdlib)
target_include_directories(ArduinoAPI PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(ArduinoAPI PUBLIC ${CMAKE_CURRENT_LIST_DIR}/api)