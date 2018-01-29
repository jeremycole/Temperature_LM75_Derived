#include <Temperature_LM75_Derived.h>

TI_TMP102 temperature;

void setup() {
  while(!Serial) {}
  
  Serial.begin(9600);

  Wire.begin();

  temperature.enableShutdownMode();
}

void loop() {
  Serial.println("Starting temperature conversion...");
  temperature.startOneShotConversion();

  Serial.println("Waiting for conversion to be ready...");
  int waited_ms = 0;
  while(!temperature.checkConversionReady()) {
    waited_ms++;
    delay(1);
  }
  
  Serial.print("Conversion ready in ");
  Serial.print(waited_ms);
  Serial.print(" ms; temperature is: ");
  Serial.print(temperature.readTemperatureF());
  Serial.println(" F!");
  Serial.println();

  delay(250);
}
