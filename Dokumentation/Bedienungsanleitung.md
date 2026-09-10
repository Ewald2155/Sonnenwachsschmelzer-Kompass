# Bedienungsanleitung - Sonnenwachsschmelzer Kompass-Version

## Grundfunktion

Die Anlage richtet sich nicht mehr mit drei LDR-Sensoren zur hellsten Stelle aus. Stattdessen wird die Sonnenrichtung aus Datum, Uhrzeit und Standort berechnet. Der Kompass MMC5603 misst die aktuelle Anlagenrichtung. Der Motor dreht die Anlage dann in Richtung der berechneten Sonnenposition.

## Tag-/Nachtschaltung

Die Tag-/Nachtschaltung ist weiterhin vorhanden. Der einzige LDR sitzt auf A1 und schaut nach oben. Er dient nur zur Lichtfreigabe, nicht zur Richtungssuche.

- A1 hell genug: Freigabe-Rampe steigt.
- A1 zu dunkel: Freigabe-Rampe faellt.
- Motor arbeitet nur, wenn Licht und Zeitfenster passen.

Das Standard-Zeitfenster ist 10:00 bis 17:00 Uhr.

## Kompass

Verwendetes Modul:

Adafruit 3-Achsen-Magnetometer MMC5603 STEMMA QT/Qwiic 5579

Anschluss am Arduino Nano:

| MMC5603 | Arduino Nano |
|---|---|
| VIN | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

Der Kompass wird starr auf dem drehenden Teil der Anlage montiert. Der Abstand von etwa 1 m zur Drehachse ist in Ordnung, solange der Kompass mit der Anlage mitdreht.

## I2C-Bus

Alle SDA-Leitungen werden parallel an A4 angeschlossen. Alle SCL-Leitungen werden parallel an A5 angeschlossen.

- LCD: meistens 0x27
- RTC DS3231: 0x68
- MMC5603: 0x30

## Motor

Der BTS7960 bleibt auf den bekannten Pins:

- D5 = L_PWM
- D6 = R_PWM
- D7 = Enable

Die Motorleitungen sollen verdrillt werden und getrennt von SDA/SCL laufen.

## Erster Test

1. I2C-Scanner laden und pruefen, ob 0x27, 0x68 und 0x30 gefunden werden.
2. MMC5603-Test laden und Kompass allein testen.
3. Danach Hauptsketch laden.
4. Anlage manuell zur Sonne drehen.
5. Im Menue Ausrichtung setzen.
6. Danach Motordrehrichtung pruefen.
