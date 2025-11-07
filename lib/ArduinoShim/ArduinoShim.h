// Brief functions to convert Arduino std methods to picosdk

#pragma once

#include "hardware/gpio.h"
#include "hardware/sync.h"
#include "pico/time.h"

#include <math.h>
#include "Common.h"

inline void pinMode(pin_size_t pin, PinMode mode) {
  switch (mode) {
  case INPUT:
    gpio_set_dir(pin, GPIO_IN);
    gpio_disable_pulls(pin);
    break;
  case OUTPUT:
    gpio_set_dir(pin, GPIO_OUT);
    break;
  case INPUT_PULLUP:
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_up(pin);
    break;
  }
}

inline PinStatus digitalRead(pin_size_t pin) {
  return (gpio_get(pin)) ? HIGH : LOW;
}

inline void digitalWrite(pin_size_t pin, PinStatus state) {
  gpio_put(pin, state);
}

inline void delayMicroseconds(uint us) {
    sleep_us(us);
}

// static uint32_t ints = 0;
// inline void noInterrupts() { ints = save_and_disable_interrupts(); }
// inline void interrupts() { restore_interrupts(ints); }

// inline void delayMicroseconds(uint us) {
//   sleep_us(us);
// }

// #ifndef max
// template <typename T> static inline T max(const T &a, const T &b) {
//   return (a > b) ? a : b;
// }
// #endif