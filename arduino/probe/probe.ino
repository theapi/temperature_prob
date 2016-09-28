/**
 * Two temperature probes with an ATTINY 85 & a MAX7219 to two 7 segment displays.
 * 
   [Ground] ---- [Thermistor] -------|------- [10k-Resistor] ---- [+5v]
                                     |
                                  Analog Pin
 */

#if defined( __AVR_ATtiny85__ )
  #define PIN_THERMISTOR_A PB3
  #define PIN_THERMISTOR_B PB4
  #define DRIVER_DIN  PB0
  #define DRIVER_SCK  PB2
  #define DRIVER_LOAD PB1
#else
  #define PIN_THERMISTOR_A A0
  #define PIN_THERMISTOR_B A1
  #define DRIVER_DIN  12
  #define DRIVER_SCK  11
  #define DRIVER_LOAD 10
#endif

#include "Max72xx.h"

// how many samples to take and average, more takes longer
// but is more 'smooth'
#define NUMSAMPLES 8

// Thermistor datasheet http://uk.farnell.com/vishay-bc-components/ntcle100e3103jb0/thermistor-10k-5-ntc-rad/dp/1187031
// resistance at 25 degrees C
#define THERMISTOR_NOMINAL 10000      
// temp. for nominal resistance (almost always 25 C)
#define THERMISTER_TEMPERATURE_NOMINAL 25  

// The beta coefficient of the thermistor (usually 3000-4000)
#define THERMISTOR_BCOEFFICIENT 3977
// the value of the 'other' resistor
#define THERMISTOR_SERIES_RESISTOR 10000   

Max72xx driver = Max72xx(DRIVER_DIN, DRIVER_SCK, DRIVER_LOAD);

void setup() {

  // Initialise the driver.
  driver.setup();
  
  // Code B decode for digits 7–0
  driver.decodeMode(0xFF);
  
  driver.setCodeDigit(1, B1100, false); // H
  driver.setCodeDigit(2, B1011, false); // E
  driver.setCodeDigit(3, B1101, false); // L
  driver.setCodeDigit(4, 0, false);     // 0
  driver.setCodeDigit(5, B1111, false);
  driver.setCodeDigit(6, B1111, false);
  driver.setCodeDigit(7, B1111, false);
  driver.setCodeDigit(8, B1111, false);

  // Turn the display on.
  driver.shutdown(false);
  delay(1000);

  driver.setCodeDigit(1, B1111, false);
  driver.setCodeDigit(2, B1111, false);
  driver.setCodeDigit(3, B1111, false);
  driver.setCodeDigit(4, B1111, false);

}

/**
 * Get the temperature from the thermistor
 */
int readTemperature(byte pin)
{
  int count = 0;
  int sum = 0;
  double value;
  int rounded;

  // Junk the first reading as the analog pin mux just changed.
  analogRead(pin);
  
  while (count < NUMSAMPLES) {
    sum += analogRead(pin);
    count++;
  }
  value = (int)sum / NUMSAMPLES;

  // convert the value to resistance
  value = 1023 / value - 1;
  value = THERMISTOR_SERIES_RESISTOR / value;


  double steinhart;
  steinhart = value / THERMISTOR_NOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= THERMISTOR_BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (THERMISTER_TEMPERATURE_NOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;   

  rounded = steinhart * 10.0;
  return rounded;
}

void loop() {

  int temperatureA = readTemperature(PIN_THERMISTOR_A);
  int temperatureB = readTemperature(PIN_THERMISTOR_B);

  char temperatureAstr[4];
  itoa(temperatureA,temperatureAstr,10);
  
  driver.setCodeDigit(1, temperatureAstr[0], false);
  driver.setCodeDigit(2, temperatureAstr[1], true);
  driver.setCodeDigit(3, temperatureAstr[2], false);

  char temperatureBstr[4];
  itoa(temperatureB,temperatureBstr,10);
  driver.setCodeDigit(5, temperatureBstr[0], false);
  driver.setCodeDigit(6, temperatureBstr[1], true);
  driver.setCodeDigit(7, temperatureBstr[2], false);

  delay(500);
}

