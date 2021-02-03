/*
 *  DS3231: Real-Time Clock. Temperature example
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
}

// ---------------------------------------------------------------------
// LOOP
//
void loop() {
  // The temperature registers are updated after every 64-second conversion.
  // If you want force temperature conversion use forceConversion()
  clock.forceConversion();

  Serial.print("Temperature: ");
  Serial.println(clock.readTemperature());

  delay(1000);
}
