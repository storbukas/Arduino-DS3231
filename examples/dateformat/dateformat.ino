/*
 *  DS3231: Real-Time Clock. Date Format
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

  // Set from UNIX timestamp
  // clock.setDateTime(1397408400);

  // Manual (YYYY, MM, DD, HH, II, SS
  // clock.setDateTime(2014, 4, 13, 19, 21, 00);
}

// ---------------------------------------------------------------------
// LOOP
//
void loop() {
  dt = clock.getDateTime();

  Serial.print("Long number format:          ");
  Serial.println(clock.dateFormat("d-m-Y H:i:s", dt));

  Serial.print("Long format with month name: ");
  Serial.println(clock.dateFormat("d F Y H:i:s", dt));

  Serial.print("Short format witch 12h mode: ");
  Serial.println(clock.dateFormat("jS M y, h:ia", dt));

  Serial.print("Today is:                    ");
  Serial.print(clock.dateFormat("l, z", dt));
  Serial.println(" days of the year.");

  Serial.print("Actual month has:            ");
  Serial.print(clock.dateFormat("t", dt));
  Serial.println(" days.");

  Serial.print("Unixtime:                    ");
  Serial.println(clock.dateFormat("U", dt));

  Serial.println();

  delay(1000);
}
