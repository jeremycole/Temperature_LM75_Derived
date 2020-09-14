/*
Similar to the BasicUsage example, but read the temperature from two LM75-
derived sensors with different addresses (0x48 and 0x49), and display them
in Celcius every 250ms. Any LM75-derived temperature should work.
*/

#include <Temperature_LM75_Derived.h>

// The Generic_LM75 class will provide 9-bit (±0.5°C) temperature for any
// LM75-derived sensor. More specific classes may provide better resolution.
Generic_LM75 temperature1(0x48);
Generic_LM75 temperature2(0x49);

void setup() {
  while(!Serial) {delay(0);}
  
  Serial.begin(9600);

  Wire.begin();
}

void loop() {
  Serial.print("Temperature 1 = ");
  Serial.print(temperature1.readTemperatureC());
  Serial.println(" C");

  Serial.print("Temperature 2 = ");
  Serial.print(temperature2.readTemperatureC());
  Serial.println(" C");

  delay(250);
}
