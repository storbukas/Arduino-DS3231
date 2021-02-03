/*
 *  DS3231: Real-Time Clock. Alarm simple
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
boolean isAlarm = false;
boolean alarmState = false;
int alarmLED = 4;

// ---------------------------------------------------------------------
// SETUP
//
void setup() {
  Serial.begin(9600);

  // Initialize DS3231
  Serial.println("Initialize DS3231");
  ;
  clock.begin();

  // Disarm alarms and clear alarms for this example, because alarms is battery
  // backed. Under normal conditions, the settings should be reset after power
  // and restart microcontroller.
  clock.armAlarm1(false);
  clock.armAlarm2(false);
  clock.clearAlarm1();
  clock.clearAlarm2();

  // Manual (Year, Month, Day, Hour, Minute, Second)
  clock.setDateTime(2014, 4, 25, 0, 0, 0);

  // Set Alarm1 - Every 20s in each minute
  // setAlarm1(Date or Day, Hour, Minute, Second, Mode, Armed = true)
  clock.setAlarm1(0, 0, 0, 10, DS3231_MATCH_S);

  // Attach Interrput 0. In Arduino UNO connect DS3231 INT to Arduino Pin 2
  attachInterrupt(0, alarmFunction, FALLING);

  // Setup LED Pin
  pinMode(alarmLED, OUTPUT);
}

// ---------------------------------------------------------------------
// LOOP
//
void loop() {
  dt = clock.getDateTime();
  Serial.println(clock.dateFormat("d-m-Y H:i:s - l", dt));

  if (isAlarm) {
    digitalWrite(alarmLED, alarmState);
    alarmState = !alarmState;
    clock.clearAlarm1();
  }

  delay(1000);
}

// ---------------------------------------------------------------------
// FUNCTIONS
//
void alarmFunction() {
  Serial.println("*** INT 0 ***");
  isAlarm = true;
}
