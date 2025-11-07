set(BMP3XX_DIR ${PROJECT_SOURCE_DIR}/extra/Adafruit_BMP3XX)
add_library(Adafruit_BMP3XX ${BMP3XX_DIR}/Adafruit_BMP3XX.cpp ${BMP3XX_DIR}/bmp3.c)
target_include_directories(Adafruit_BMP3XX PUBLIC ${BMP3XX_DIR})
target_link_libraries(Adafruit_BMP3XX PUBLIC Pico_BusIO)