#ifndef TI_TMPSERIES_H
#define TI_TMPSERIES_H

#include <Wire.h>

class TI_TMPseries {
private:
  static const uint8_t REGISTER_TEMPERATURE   = 0x00;
  static const uint8_t REGISTER_CONFIGURATION = 0x01;
  static const uint8_t REGISTER_T_LOW         = 0x02;
  static const uint8_t REGISTER_T_HIGH        = 0x03;

  static const uint8_t TEMPERATURE_WIDTH = 16;
  static const uint8_t TEMPERATURE_FRAC_WIDTH = 8;

  static constexpr float TEMPERATURE_FRAC_FACTOR = 1.0 / (float)(1 << TEMPERATURE_FRAC_WIDTH);
  
  TwoWire *bus;
  uint8_t i2c_address;
  uint8_t resolution;
  uint16_t resolution_mask;

  void setInternalResolution(uint8_t resolution) {
    this->resolution = resolution;
    this->resolution_mask = ~(uint16_t)((1 << (TEMPERATURE_WIDTH - resolution)) - 1);
  }

  int16_t readIntegerTemperatureRegister();

public:
  static const uint8_t DEFAULT_I2C_ADDRESS_TMP102 = 0x48;

  TI_TMPseries(TwoWire *bus, uint8_t i2c_address) {
    this->bus = bus;
    this->i2c_address = i2c_address;
    setInternalResolution(12);
  }

  float readTemperatureC();
  float readTemperatureF();
};

#endif // TI_TMPSERIES_H
