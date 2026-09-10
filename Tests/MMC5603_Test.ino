#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MMC56x3.h>

Adafruit_MMC5603 mmc = Adafruit_MMC5603(12345);

float norm360(float a) {
  while (a < 0) a += 360.0;
  while (a >= 360.0) a -= 360.0;
  return a;
}

void setup() {
  Wire.begin();
  Wire.setClock(100000UL);
  Serial.begin(9600);
  while (!Serial) {}

  Serial.println("MMC5603 Kompass-Test");

  if (!mmc.begin(MMC56X3_DEFAULT_ADDRESS, &Wire)) {
    Serial.println("MMC5603 nicht gefunden. Anschluss und Library pruefen.");
    while (1) delay(10);
  }

  Serial.println("MMC5603 gefunden.");
}

void loop() {
  sensors_event_t event;
  mmc.getEvent(&event);

  float heading = atan2(event.magnetic.y, event.magnetic.x) * 180.0 / PI;
  heading = norm360(heading);

  Serial.print("X: "); Serial.print(event.magnetic.x);
  Serial.print("  Y: "); Serial.print(event.magnetic.y);
  Serial.print("  Z: "); Serial.print(event.magnetic.z);
  Serial.print("  Winkel: "); Serial.println(heading);

  delay(500);
}
