/*
 *  DS3231: Real-Time Clock. SQW & 32kHz Example
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
boolean state;

// ---------------------------------------------------------------------
// SETUP
//
void setup() {
  Serial.begin(9600);

  // Initialize DS3231
  Serial.println("Initialize DS3231");
  ;
  clock.begin();

  // disable 32kHz
  clock.enable32kHz(false);

  // Select output as rate to 1Hz
  clock.setOutput(DS3231_1HZ);

  // Enable output
  clock.enableOutput(true);

  // Check config

  if (clock.isOutput()) {
    Serial.println("Oscilator is enabled");
  } else {
    Serial.println("Oscilator is disabled");
  }

  switch (clock.getOutput()) {
    case DS3231_1HZ:
      Serial.println("SQW = 1Hz");
      break;
    case DS3231_4096HZ:
      Serial.println("SQW = 4096Hz");
      break;
    case DS3231_8192HZ:
      Serial.println("SQW = 8192Hz");
      break;
    case DS3231_32768HZ:
      Serial.println("SQW = 32768Hz");
      break;
    default:
      Serial.println("SQW = Unknown");
      break;
  }
}

// ---------------------------------------------------------------------
// LOOP
//
void loop() {
  // Togle 32kHz output
  clock.enable32kHz(state);
  state = !state;
  delay(2000);
}
