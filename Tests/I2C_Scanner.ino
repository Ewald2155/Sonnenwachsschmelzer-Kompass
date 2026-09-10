#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("I2C Scanner gestartet");
}

void loop() {
  byte error, address;
  int devices = 0;

  Serial.println("Suche I2C-Geraete...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Gefunden: 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      devices++;
    }
  }

  if (devices == 0) {
    Serial.println("Keine I2C-Geraete gefunden");
  } else {
    Serial.print("Anzahl gefunden: ");
    Serial.println(devices);
  }

  Serial.println();
  delay(3000);
}
