/*
 *  DS3231: Real-Time Clock. Simple example
 *
 *  created 03 Feb 2021
 *  by Lars Erik Storbukås <https://github.com/storbukas>
 *
 *  Source: https://github.com/storbukas/DS3231
 *  Original source: https://github.com/jarzebski/Arduino-DS3231>
 *
 *  Licensed under the GPL-3.0 License
 *  https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 */

// ---------------------------------------------------------------------
// INCLUDES
//
#include <DS3231.h>
#include <Wire.h>

// ---------------------------------------------------------------------
// VARIABLES
//
DS3231 clock;
RTCDateTime dt;

// ---------------------------------------------------------------------
// SETUP
//
void setup() {
  Serial.begin(9600);

  // Initialize DS3231
  Serial.println("Initialize DS3231");
  ;
  clock.begin();

  // Set sketch compiling time
  clock.setDateTime(__DATE__, __TIME__);
}

// ---------------------------------------------------------------------
// LOOP
//
void loop() {
  dt = clock.getDateTime();

  // For leading zero look to DS3231_dateformat example

  Serial.print("Raw data: ");
  Serial.print(dt.year);
  Serial.print("-");
  Serial.print(dt.month);
  Serial.print("-");
  Serial.print(dt.day);
  Serial.print(" ");
  Serial.print(dt.hour);
  Serial.print(":");
  Serial.print(dt.minute);
  Serial.print(":");
  Serial.print(dt.second);
  Serial.println("");

  delay(1000);
}
