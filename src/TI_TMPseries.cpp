#include "TI_TMPseries.h"

// TODO: Deal with sign bit for negative numbers.
// TODO: Deal with 13-bit temperature.
int16_t TI_TMPseries::readIntegerTemperatureRegister() {
  // Select the temperature register.
  bus->beginTransmission(i2c_address);
  bus->write(REGISTER_TEMPERATURE);
  bus->endTransmission();

  uint8_t t_raw;
  int16_t t;

  // Read the temperature data; MSB first.
  bus->requestFrom(i2c_address, (uint8_t) 2);
  t_raw = bus->read();
  t = t_raw << 8;
  
  t_raw = bus->read();
  t |= t_raw;
  bus->endTransmission();

  t >>= 4;

  return t;
}

float TI_TMPseries::readTemperatureC() {
  return (float)readIntegerTemperatureRegister() / 16.0;
}

