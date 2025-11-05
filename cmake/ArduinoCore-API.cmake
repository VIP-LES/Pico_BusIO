set(API_DIR ${PROJECT_SOURCE_DIR}/external/ArduinoCore-API)

add_library(ArduinoCore-API INTERFACE)
target_include_directories(ArduinoCore-API INTERFACE ${API_DIR}/api)