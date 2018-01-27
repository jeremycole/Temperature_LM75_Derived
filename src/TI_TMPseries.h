#ifndef TI_TMPSERIES_H
#define TI_TMPSERIES_H

#include <Wire.h>

class TI_TMPseries {
private:
  static const uint8_t REGISTER_TEMPERATURE   = 0x00;
  static const uint8_t REGISTER_CONFIGURATION = 0x01;
  static const uint8_t REGISTER_T_LOW         = 0x02;
  static const uint8_t REGISTER_T_HIGH        = 0x03;
  
  TwoWire *bus;
  uint8_t i2c_address;

  int16_t readIntegerTemperatureRegister();

public:
  static const uint8_t DEFAULT_I2C_ADDRESS_TMP102 = 0x48;

  TI_TMPseries(TwoWire *bus, uint8_t i2c_address) {
    this->bus = bus;
    this->i2c_address = i2c_address;
  }
  
  float readTemperatureC();
};

#endif // TI_TMPSERIES_H
