# Sonnenwachsschmelzer-Kompass

Projekt fuer den Dini Bee Sonnenwachsschmelzer / Solar-Tracker mit Arduino Nano, LCD 20x4 I2C, DS3231 RTC, BTS7960 Motorsteuerung, einem LDR als Tag-/Nachtfreigabe und Adafruit MMC5603 Kompass.

## Aktueller Stand

Aktuelle Hauptversion:

- `SolarTracker_Vers_2026_13_MMC5603_Zeit10_17`
- Arbeitszeitfenster: 10:00 bis 17:00 Uhr
- Tag-/Nachtschaltung ueber einen LDR auf A1
- Kompassfuehrung ueber Adafruit MMC5603
- RTC DS3231 fuer Datum und Uhrzeit
- Standort: 8541 Bad Schwanberg

Der aktuelle Sketch liegt im Ordner `Sketches` als ZIP-Archiv. Dieses Archiv enthaelt die vollstaendige `.ino` Datei.

## Ordner

- `Sketches` - aktuelle und spaetere Programmversionen
- `Tests` - kleine Testprogramme fuer I2C und MMC5603
- `Dokumentation` - kurze Bedienungs- und Projektbeschreibung
- `CHANGELOG.md` - Aenderungsprotokoll

## Benoetigte Arduino-Bibliotheken

- Wire
- EEPROM
- LiquidCrystal_I2C
- RTClib von Adafruit
- Adafruit MMC56x3
- Adafruit Unified Sensor
- Adafruit BusIO

## Wichtige Pinbelegung

| Funktion | Arduino Nano |
|---|---|
| LDR Lichtfreigabe | A1 |
| SYS Enable | A3 |
| BTS7960 L_PWM | D5 |
| BTS7960 R_PWM | D6 |
| BTS7960 Enable | D7 |
| Encoder 1 CLK / DT / SW | D2 / D4 / D9 |
| Encoder 2 CLK / DT / SW | D3 / D10 / D11 |
| Status LED | D13 |
| I2C SDA | A4 |
| I2C SCL | A5 |

I2C-Geraete parallel anschliessen: LCD, DS3231 und MMC5603 gemeinsam an SDA/SCL.
