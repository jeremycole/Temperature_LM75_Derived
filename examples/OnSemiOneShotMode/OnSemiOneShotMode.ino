/*
This example is specific to the NCT75 sensor from OnSemi, as it uses a non-standard
one-shot method

Shut down the sensor, and use one-shot conversion to request a single immediate
temperature conversion.

In order to save power, LM75-derived temperature sensors can be placed in
"shutdown" mode where they stop making regular temperature conversions. Some
sensors support a "one-shot" mode to request a single temperature conversion
from an otherwise shutdown sensor. This can be used for two purposes:

  * To conserve (a lot of) power by making very infrequent temperature
    conversions, such as every few minutes.

  * To convert more frequently than the usually-supported temperature
    conversion rates allow on very fast sensors (such as TMP102/TMP112).
*/

#include <Temperature_LM75_Derived.h>

ON_NCT75 temperature;

void setup() {
  while(!Serial) {}

  Serial.begin(9600);

  Wire.begin();

  temperature.enableOneShotMode();
}

void loop() {
  Serial.println("Starting temperature conversion...");
  temperature.startOneShotConversion();

  Serial.println("Waiting for conversion to be ready...");

  /* 
  The NCT75 doesn't offer any way to check when a conversion is done
  The datasheet instead lists the typical conversion time to be 48.5 ms.
  As it doesn't list the max conversion time, we wait ~2x the typical time
  */
  delay(100);

  Serial.print("Temperature is: ");
  Serial.print(temperature.readTemperatureC());
  Serial.println(" C!");
  Serial.println();

  delay(250);
}
