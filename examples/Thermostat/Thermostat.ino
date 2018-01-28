#include <TI_LM_TMP_series.h>

TI_TMP102 temperature;

void setup() {
  while(!Serial) {}
  
  Serial.begin(9600);

  Wire.begin();

  temperature.setTemperatureLowC(25.0);
  temperature.setTemperatureHighC(27.0);
  temperature.setAlertActiveHigh();
}

void loop() {
  Serial.print("T = ");
  Serial.print(temperature.readTemperatureC());
  Serial.print(", T_low = ");
  Serial.print(temperature.readTemperatureLowC());
  Serial.print(", T_high = ");
  Serial.print(temperature.readTemperatureHighC());
  Serial.print(", alert = ");
  Serial.println(temperature.checkAlert() ? "HIGH" : "LOW");

  delay(250);
}
