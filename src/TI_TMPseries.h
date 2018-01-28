#ifndef TI_TMPSERIES_H
#define TI_TMPSERIES_H

#include <Wire.h>

class TI_TMPseries {
public:

  // The layout of registers accessed through the I2C protocol.
  struct RegisterLayout {
    uint8_t temperature;
    uint8_t configuration;
    uint8_t temperature_low;
    uint8_t temperature_high;
  };

  // Attributes about a device or family of devices (if the attributes are shared).
  struct Attributes {
    uint8_t temperature_width;
    uint8_t default_temperature_resolution;
    uint8_t default_temperature_frac_width;
    uint8_t max_temperature_resolution;
    RegisterLayout *registers;
  };

  // The typical I2C address for any device.
  static const uint8_t DEFAULT_I2C_ADDRESS = 0x48;

protected:

  TwoWire *bus;
  uint8_t i2c_address;
  uint8_t resolution;
  uint16_t resolution_mask;
  uint8_t temperature_frac_width;
  float temperature_frac_factor;
  Attributes *attributes;

  // Set the internal resolution of the temperature sensor, which affects
  // conversions and which bits are discarded.
  void setInternalResolution(uint8_t resolution) {
    this->resolution = resolution;
    this->resolution_mask = ~(uint16_t)((1 << (attributes->temperature_width - resolution)) - 1);
  }

  void setInternalTemperatureFracWidth(uint8_t temperature_frac_width) {
    this->temperature_frac_width = temperature_frac_width;
    temperature_frac_factor = 1.0 / (float)(1 << temperature_frac_width);
  }

  int16_t readIntegerTemperatureRegister();

public:

  TI_TMPseries(TwoWire *bus, uint8_t i2c_address, Attributes *attributes) {
    this->bus = bus;
    this->i2c_address = i2c_address;
    this->attributes = attributes;

    setInternalResolution(attributes->default_temperature_resolution);
    setInternalTemperatureFracWidth(attributes->default_temperature_frac_width);
  }

  float readTemperatureC();
  float readTemperatureF();
};

class TI_TMP75_Compatible : public TI_TMPseries {
private:

  enum ConfigurationBits {
    OneShot           = 7, // mask 0x80, length 1 bit
    Resolution        = 5, // mask 0x60, length 2 bits
    FaultQueueLength  = 3, // mask 0x18, length 2 bits
    AlertPolarity     = 2, // mask 0x04, length 1 bit
    ThermostatMode    = 1, // mask 0x02, length 1 bit
    Shutdown          = 0, // mask 0x01, length 1 bit
  };

  uint8_t readConfigurationRegister();
  void writeConfigurationRegister(uint8_t configuration);

  uint8_t readConfigurationBits(uint8_t bits) {
    return readConfigurationRegister() & bits;
  }

  bool checkConfigurationBits(uint8_t bits) {
    return (readConfigurationRegister() & bits) == bits;
  }

  void setConfigurationBits(uint8_t bits);
  void clearConfigurationBits(uint8_t bits);
  void setConfigurationBitValue(uint8_t value, uint8_t start, uint8_t width);

public:

  enum Resolution {
    Resolution_9_bits   = 0,
    Resolution_10_bits  = 1,
    Resolution_11_bits  = 2,
    Resolution_12_bits  = 3,
  };

  enum FaultQueueLength {
    FaultQueueLength_1_fault   = 0,
    FaultQueueLength_2_faults  = 1,
    FaultQueueLength_4_faults  = 2,
    FaultQueueLength_6_faults  = 3,
  };

  TI_TMP75_Compatible(TwoWire *bus, uint8_t i2c_address, Attributes *attributes)
    : TI_TMPseries(bus, i2c_address, attributes) { };

  void startOneShotConversion() {
    setConfigurationBits(_BV(ConfigurationBits::OneShot));
  }

  bool checkConversionReady() {
    return checkConfigurationBits(_BV(ConfigurationBits::OneShot));
  }

  void setResolution(enum Resolution resolution) {
    setConfigurationBitValue(resolution, ConfigurationBits::Resolution, 2);
  }

  void setFaultQueueLength(enum FaultQueueLength faults) {
    setConfigurationBitValue(faults, ConfigurationBits::FaultQueueLength, 2);
  }

  void setAlertActiveLow() {
    clearConfigurationBits(_BV(ConfigurationBits::AlertPolarity));
  }

  void setAlertActiveHigh() {
    setConfigurationBits(_BV(ConfigurationBits::AlertPolarity));
  }

  void setThermostatComparatorMode() {
    clearConfigurationBits(_BV(ConfigurationBits::ThermostatMode));
  }

  void setThermostatInterruptMode() {
    setConfigurationBits(_BV(ConfigurationBits::ThermostatMode));
  }

  void enableShutdownMode() {
    setConfigurationBits(_BV(ConfigurationBits::Shutdown));
  }

  void disableShutdownMode() {
    clearConfigurationBits(_BV(ConfigurationBits::Shutdown));
  }
};

extern TI_TMPseries::Attributes TI_TMP102_Attributes;

class TI_TMP102 : public TI_TMP75_Compatible {
private:

  enum ExtendedConfigurationBits {
    ConversionRate  = 6, // mask 0x00c0, length 2 bits
    Alarm           = 5, // mask 0x0020, length 1 bit
    ExtendedMode    = 4, // mask 0x0010, length 1 bit
  };

  enum ConversionRate {
    ConversionRate_0_25Hz = 0,
    ConversionRate_1_Hz   = 1,
    ConversionRate_4_Hz   = 2,
    ConversionRate_8_Hz   = 3,
  };

  uint16_t readExtendedConfigurationRegister();
  void writeExtendedConfigurationRegister(uint16_t configuration);

  uint16_t readExtendedConfigurationBits(uint16_t bits) {
    return readExtendedConfigurationRegister() & bits;
  }

  bool checkExtendedConfigurationBits(uint16_t bits) {
    return (readExtendedConfigurationRegister() & bits) == bits;
  }

  void setExtendedConfigurationBits(uint16_t bits);
  void clearExtendedConfigurationBits(uint16_t bits);
  void setExtendedConfigurationBitValue(uint16_t value, uint8_t start, uint8_t width);

public:

  TI_TMP102(TwoWire *bus = &Wire, uint8_t i2c_address = DEFAULT_I2C_ADDRESS)
    : TI_TMP75_Compatible(bus, i2c_address, &TI_TMP102_Attributes) { };

  TI_TMP102(uint8_t i2c_address)
    : TI_TMP75_Compatible(&Wire, i2c_address, &TI_TMP102_Attributes) { };

  void setConversionRate(enum ConversionRate rate) {
    setExtendedConfigurationBitValue(rate, ExtendedConfigurationBits::ConversionRate, 2);
  }

  bool checkAlarm() {
    return checkExtendedConfigurationBits(ExtendedConfigurationBits::Alarm);
  }

  void enableExtendedMode();
  void disableExtendedMode();
};

#endif // TI_TMPSERIES_H
