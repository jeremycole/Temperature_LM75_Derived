#include "TI_TMPseries.h"

static float convertCtoF(float c) {
  return c * 1.8 + 32;
}

static float convertFtoC(float f) {
  return (f - 32) / 1.8;
}

int16_t TI_TMPseries::readIntegerTemperatureRegister() {
  // Select the temperature register.
  bus->beginTransmission(i2c_address);
  bus->write(REGISTER_TEMPERATURE);
  bus->endTransmission();

  // Start a transaction to read the register data.
  bus->requestFrom(i2c_address, (uint8_t) (resolution <= 8 ? 1 : 2));

  // Read the most significant byte of the temperature data.
  uint16_t t = bus->read() << 8;
  
  // Read the least significant byte of the temperature data, if requested.
  if (resolution > 8) {
    t |= bus->read();
  }

  // Finished reading the register data.
  bus->endTransmission();

  // Mask out unused/reserved bit from the full 16-bit register.
  t &= resolution_mask;

  // Read the raw memory as a 16-bit signed integer and return.
  return *(int16_t *)(&t);
}

float TI_TMPseries::readTemperatureC() {
  return (float)readIntegerTemperatureRegister() * TEMPERATURE_FRAC_FACTOR;
}

float TI_TMPseries::readTemperatureF() {
  return convertCtoF(readTemperatureC());
}

