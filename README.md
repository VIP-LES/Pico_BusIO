# Pico_BusIO

**Pico_BusIO** is a standalone port of the Arduino `Wire` and `SPI` interfaces for the RP2040, designed specifically to support **Adafruit_BusIO**-based sensor libraries in native **pico-sdk** CMake projects.  
It allows Adafruit sensor drivers to be used on the Raspberry Pi Pico **without the Arduino framework**, platform files, or the Arduino build system.

This project was adapted from the `Wire` and `SPI` implementations in **Arduino-Pico**, refactored and simplified for direct integration in non-Arduino environments.

---

## Example: Reading from a BMP388 / BMP390

```cpp
#include "Adafruit_BMP3XX.h"
#include "Wire.h"
#include "pico/stdlib.h"

#define I2C_BLOCK i2c0
#define PIN_SDA 16
#define PIN_SCL 17
#define SEALEVELPRESSURE_HPA (1013.25)

int main() {
  stdio_init_all();
  while(!stdio_usb_connected())
    sleep_ms(100);

  printf("Adafruit BMP388 / BMP390 test\n");

  Adafruit_BMP3XX bmp;
  TwoWire i2c(I2C_BLOCK, PIN_SDA, PIN_SCL);
  i2c.begin();

  if (!bmp.begin_I2C(0x77, &i2c)) {
    printf("Could not find a valid BMP3 sensor\n");
    while(1);
  }

  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);

  while(1) {
    if (!bmp.performReading()) return 0;

    printf("Temperature = %.3f °C\n", bmp.temperature);
    printf("Pressure = %.3f hPa\n", bmp.pressure / 100.0);
    printf("Altitude = %.0f m\n", bmp.readAltitude(SEALEVELPRESSURE_HPA));

    sleep_ms(2000);
  }
}
```

## CMake Integration

Add this repository as a subdirectory:

```
add_subdirectory(Pico_BusIO)

target_link_libraries(your_target
  PRIVATE
    pico_stdlib
    pico_busio
)
```

## Licensing

This project contains code adapted from Arduino-Pico, originally released under the MIT License.  
All original copyright notices are preserved.  
Modifications for Pico_BusIO are also released under the MIT License.  

See `LICENSE` for full details.